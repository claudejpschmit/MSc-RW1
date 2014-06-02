#include <iostream>
#include <fstream>

#include <ctime>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>

#define PI 3.14159265359

using namespace std;

int main( ) {

    /* Using Mersenne-Twister as the random number generator
     * as it has much better statistics than plain
     * linear congruential RNG that comes with GCC.
     */
    boost::mt19937 rng(time (0));
    boost::random::uniform_real_distribution<> uniformDistribution(0, 2*PI);
    double a = uniformDistribution(rng); 
    cout << a << endl;
    return 0;
}
