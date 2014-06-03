#pragma once

#include <iostream>

#include "helper.hpp"

#include <boost/random/mersenne_twister.hpp>

#define PI 3.14159265359

class StepGenerator {

public:
    StepGenerator();

    void generateNext(position& next, position last);

private: 
    double generateAngle(double lowBound, double highBound);
    
    /* Using Mersenne-Twister as the random number generator
     * as it has much better statistics than plain
     * linear congruential RNG that comes with GCC.
     */
    boost::mt19937 rng;
};

