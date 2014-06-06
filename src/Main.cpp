#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "StepGenerator.hpp"
#include "position.hpp"
#include <vector>

#define ITERATIONS 100

using namespace std;

int main(int argc, char *argv[]) {
    /** Makes sure that the parameters are entered correctly when run */
    if (argc < 3) {
        cout << "This program should be run as: "
            << argv[0] << " number_of_walks" << " number_of_proteins" << endl;
        return -1;
    }

    int NoWalks, NoProteins;
    istringstream (argv[1]) >> NoWalks;
    istringstream (argv[2]) >> NoProteins;

    if (NoWalks < 1) {
        cout << "number of walks should be > 1" << endl;
        return -1;
    }
    if (NoProteins < 0) {
        cout << "number of proteins should be positive" << endl;
        return -1;
    }
    if (NoWalks < NoProteins) {
        cout << "number of proteins should be smaller than the number of steps" << endl;
        return -1;
    }

   
    //creating a single n-step random walk
    cout << "Creating a single n-step random walk ..." << endl;
    position current(0,0,0);
    position next(0,0,0);
    vector<position> randomWalkStored;
    randomWalkStored.push_back(current);
    StepGenerator RW;

    ofstream randomWalk("randomWalk.txt");
    randomWalk << randomWalkStored[0].x << " " << randomWalkStored[0].y <<  " " << randomWalkStored[0].z << endl;
 
    for (int i = 0; i < NoWalks; ++i) {

        RW.generateNext(next, current);
        randomWalkStored.push_back(next);
        randomWalk << randomWalkStored[i + 1].x << " " << randomWalkStored[i + 1].y <<  " " << randomWalkStored[i + 1].z << endl;
        current = next;
    }

    randomWalk.close();

    // adding protein to the random walk
    cout << "adding protein to the random walk ..." << endl;

    vector<position> proteins;

    for (int i = 1; i <= NoProteins; ++i)
    {
        // -1 to ensure that we don't have a protein of the endpoint.
        // proteins are uniformly distributed.
        proteins.push_back(randomWalkStored[i * ((NoWalks - 1)/NoProteins)]);
    }

    ofstream proteinPositions("proteins.txt");
    for (int i = 0; i < NoProteins; ++i)
    {
        proteinPositions << proteins[i].x << " " << proteins[i].y << " " << proteins[i].z << endl;
    }

    proteinPositions.close();
    // creating End to end distance data

    cout << "Creating end to end distance data ..." << endl;
    ofstream endtoend("endtoend.txt");
    int j = 10;
    vector<double> averageDistances;
    while (j <= NoWalks) {
        double av = 0;
        double avSq = 0;

        for (int k = 0; k < ITERATIONS; ++k){
            next.set(0,0,0);
            current = next;

            for (int i = 0; i < j; ++i) {

                RW.generateNext(next, current);
                current = next;
            }
            av += current.ETEDist();
            avSq += current.ETEDist() * current.ETEDist();
        }
        av = av/ITERATIONS;
        avSq = avSq/ITERATIONS;
        averageDistances.push_back(av);

        /*  Gives average end to end distance + standard deviation on them.
         *
         */
        endtoend << j << " " << av << " " 
            << sqrt(avSq - av * av)/sqrt(NoWalks/10)  << endl;
        j += 10;
    }
    endtoend.close();

    return 0;
}
