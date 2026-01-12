#include "math_utils.h"
#include <cmath>
#include <numeric>

namespace math_utils {

    double distance(const Point& a, const Point& b) {
        return std::sqrt((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y));
    }

    Point centroid(const std::vector<Point>& points) {
        double sumX = std::accumulate(points.begin(), points.end(), 0.0,
            [](double sum, const Point& p) { return sum + p.x; });

        double sumY = std::accumulate(points.begin(), points.end(), 0.0,
            [](double sum, const Point& p) { return sum + p.y; });

        double n = static_cast<double>(points.size());
        return { sumX / n, sumY / n };
    }

}