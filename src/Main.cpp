#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "StepGenerator.hpp"
#include "helper.hpp"
#include <vector>

#define ITERATIONS 100

using namespace std;

int main(int argc, char *argv[]) {
    /** Makes sure that the parameters are entered correctly when run */
    if (argc < 2) {
        cout << "This program should be run as: "
            << argv[0] << " number_of_walks" << endl;
        return -1;
    }

    int NoWalks;
    istringstream (argv[1]) >> NoWalks;

    if (NoWalks < 1) {
        cout << "number of walks should be positive" << endl;
        return -1;
    }
    
    //creating a single n-step random walk
    position current, next;
    next.x = 0;
    next.y = 0;
    next.z = 0;
    current = next;
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

    // creating End to end distance data
    ofstream endtoend("endtoend.txt");
    int j = 10;
    vector<double> averageDistances;
    while (j <= NoWalks) {
        double av = 0;
        double avSq = 0;

        for (int k = 0; k < ITERATIONS; ++k){
            next.x = 0;
            next.y = 0;
            next.z = 0;
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
