#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>

namespace math_utils {

    struct Point {
        double x;
        double y;
    };

    double distance(const Point& a, const Point& b);
    Point centroid(const std::vector<Point>& points);

}

#endif