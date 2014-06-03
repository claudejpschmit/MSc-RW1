#include <iostream>
#include <fstream>
#include <sstream>
#include "StepGenerator.hpp"

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
    return 0;
}
