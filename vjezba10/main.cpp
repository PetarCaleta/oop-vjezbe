#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

#include "math_utils.h"
#include <fstream>

#include "Student.h"

void vectorAlgorithms() {
    std::vector<int> v = { 1, 2, 3, 4, 8, 11, 16, 21 };

    // prvi neparni
    auto it = std::find_if(v.begin(), v.end(),
        [](int x) { return x % 2 != 0; });
    if (it != v.end())
        std::cout << "Prvi neparni: " << *it << "\n";

    // ukupan broj neparnih
    int countOdd = std::count_if(v.begin(), v.end(),
        [](int x) { return x % 2 != 0; });
    std::cout << "Broj neparnih: " << countOdd << "\n";

    // prosjek neparnih
    int sumOdd = std::accumulate(v.begin(), v.end(), 0,
        [](int sum, int x) {
            return (x % 2 != 0) ? sum + x : sum;
        });

    double avgOdd = countOdd == 0 ? 0.0 :
        static_cast<double>(sumOdd) / countOdd;

    std::cout << "Prosjek neparnih: " << avgOdd << "\n";

    // zamijeni potencije broja 2 sa 2
    std::replace_if(v.begin(), v.end(),
        [](int x) { return x > 0 && (x & (x - 1)) == 0; }, 2);

    // ispis: parni pa neparni (sortirani)
    std::vector<int> even, odd;
    std::copy_if(v.begin(), v.end(), std::back_inserter(even),
        [](int x) { return x % 2 == 0; });
    std::copy_if(v.begin(), v.end(), std::back_inserter(odd),
        [](int x) { return x % 2 != 0; });

    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());

    std::cout << "Parni: ";
    std::copy(even.begin(), even.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nNeparni: ";
    std::copy(odd.begin(), odd.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n\n";
}


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

    
    std::cout << "Tocke:\n";
    for (const auto& p : points)
        std::cout << p.x << " " << p.y << "\n";

    std::cout << "\n";
}

void studentAlgorithms() {
    using namespace student_records;

    std::ifstream file("studenti.txt");
    std::vector<Student> students;

    Student s;
    while (file >> s.ime >> s.prezime >> s.bodovi)
        students.push_back(s);

    // FILTER
    students.erase(
        std::remove_if(students.begin(), students.end(),
            [](const Student& s) { return s.bodovi < 40; }),
        students.end());

    // MAP
    std::transform(students.begin(), students.end(), students.begin(),
        [](Student s) {
            s.bodovi = bodovi_u_ocjenu(s.bodovi);
            return s;
        });

    // REDUCE
    double avg = std::accumulate(students.begin(), students.end(), 0.0,
        [](double sum, const Student& s) {
            return sum + s.bodovi;
        }) / static_cast<double>(students.size());

    // sort po prezimenu
    std::sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.prezime < b.prezime;
        });

   
    std::cout << "Studenti:\n";
    for (const auto& s : students)
        std::cout << s.ime << " " << s.prezime
        << " ocjena: " << s.bodovi << "\n";

    std::cout << "Prosjek ocjena: " << avg << "\n";
}

int main() {
    vectorAlgorithms();
    pointAlgorithms();
    studentAlgorithms();
    return 0;
}