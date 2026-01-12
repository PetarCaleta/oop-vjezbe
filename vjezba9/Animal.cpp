#include "Animal.h"

Animal::Animal(const std::string& name, int age, double weight)
    : name(name), age(age), weight(weight) {
    if (name.empty() || age < 0 || weight <= 0) {
        throw std::invalid_argument("Invalid animal data");
    }
}

std::string Animal::getName() const {
    return name;
}