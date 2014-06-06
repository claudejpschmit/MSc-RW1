#pragma once

struct position {
    position(double x, double y, double z);
    double x, y, z;
    double ETEDist();
    void set(double x, double y, double z);
};


