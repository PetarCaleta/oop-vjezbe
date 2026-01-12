#include "Elephant.h"
#include <stdexcept>

Elephant::Elephant(const std::string& name, int age, double weight)
    : Animal(name, age, weight),
    Mammal(name, age, weight, false) {
}

std::string Elephant::getSpecies() const {
    return "Elephant";
}

double Elephant::getDailyFood() const {
    double food = weight * 0.04;
    if (food <= 0) throw std::logic_error("Invalid food amount");
    return food;
}