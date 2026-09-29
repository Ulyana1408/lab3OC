#include "math_func.h"
#include <stdexcept>

double linear_interp(double x0, double y0,
                     double x1, double y1,
                     double x) {
    if (x0 == x1) {
        throw std::invalid_argument("x0 and x1 must be different");
    }

    double y = y0 + (y1 - y0) * (x - x0) / (x1 - x0);
    return y;
}