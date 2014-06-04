#include "helper.hpp"

#include <cmath>

double position::ETEDist() {
    return sqrt(x * x  + y * y + z * z);

}
