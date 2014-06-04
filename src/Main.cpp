#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "StepGenerator.hpp"
#include "helper.hpp"

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

    position current, next;
    next.x = 0;
    next.y = 0;
    next.z = 0;
    current = next;

    StepGenerator RW;

    ofstream randomWalk("randomWalk.txt");

    for (int i = 0; i < NoWalks; ++i) {

        RW.generateNext(next, current);
        randomWalk << next.x << " " << next.y << " " << next.z << endl;
        current = next;
    }

    randomWalk.close();

    ofstream endtoend("endtoend.txt");
    int j = 10;
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

        /*  Gives average end to end distance + standard deviation on them.
         *
         */
        endtoend << j << " " << av << " " << sqrt(avSq - av * av)  << endl;
        j += 10;
    }
    endtoend.close();

    return 0;
}
