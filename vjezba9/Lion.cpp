#include "Lion.h"
#include <stdexcept>

Lion::Lion(const std::string& name, int age, double weight)
    : Animal(name, age, weight),
    Mammal(name, age, weight, true) {
}

std::string Lion::getSpecies() const {
    return "Lion";
}

double Lion::getDailyFood() const {
    double food = weight * 0.06;
    if (food <= 0) throw std::logic_error("Invalid food amount");
    return food;
}