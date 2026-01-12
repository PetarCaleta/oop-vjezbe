#include "math_utils.h"
#include <fstream>

void pointAlgorithms() {
    using math_utils::Point;

    std::ifstream file("points.txt");
    std::vector<Point> points;

    std::istream_iterator<double> it(file), end;
    while (it != end) {
        double x = *it++;
        double y = *it++;
        points.push_back({ x, y });
    }

    // sort po udaljenosti od (0,0)
    std::sort(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            return math_utils::distance(a, { 0,0 }) <
                math_utils::distance(b, { 0,0 });
        });

    // count_if - prvi kvadrant
    int firstQuadrant = std::count_if(points.begin(), points.end(),
        [](const Point& p) { return p.x > 0 && p.y > 0; });

    std::cout << "Tocaka u prvom kvadrantu: "
        << firstQuadrant << "\n";

    // centroid
    Point c = math_utils::centroid(points);
    std::cout << "Centroid: (" << c.x << ", " << c.y << ")\n";

    // transform - pomak (5,3)
    std::transform(points.begin(), points.end(), points.begin(),
        [](Point p) {
            p.x += 5;
            p.y += 3;
            return p;
        });

    // remove_if + erase
    points.erase(
        std::remove_if(points.begin(), points.end(),
            [](const Point& p) { return p.x < 0 && p.y < 0; }),
        points.end());

    // ispis
    std::cout << "Tocke:\n";
    for (const auto& p : points)
        std::cout << p.x << " " << p.y << "\n";

    std::cout << "\n";
}