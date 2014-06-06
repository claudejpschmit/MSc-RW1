#include "helper.hpp"

#include <cmath>

position::position(double x, double y, double z)
    :
    x(x),
    y(y),
    z(z)
{
}

double position::ETEDist() {
    return sqrt(x * x  + y * y + z * z);

}

void position::set(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
