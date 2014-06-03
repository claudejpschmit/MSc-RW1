#include "StepGenerator.hpp"
#include <sys/time.h>
#include <cmath>

#include <boost/random/uniform_real_distribution.hpp>

#define PI 3.14159265359

StepGenerator::StepGenerator()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    rng.seed(1000000*tv.tv_sec + tv.tv_usec);
}

void StepGenerator::generateNext(position& next, position last)
{
    double theta = generateAngle(0,2*PI);
    double phi = generateAngle(0,PI);
    next.x = last.x + cos(theta) * sin(phi);
    next.y = last.y + sin(theta) * sin(phi);
    next.z = last.z + cos(phi);
}


double StepGenerator::generateAngle(double lowBound, double highBound)
{
    boost::random::uniform_real_distribution<> 
        uniformDistribution(lowBound, highBound);
    return uniformDistribution(rng); 
}


