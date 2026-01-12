#include "Mammal.h"

Mammal::Mammal(const std::string& name, int age, double weight, bool hasFur)
    : Animal(name, age, weight), hasFur(hasFur) {
    std::cout << "Stvoren sisavac "
        << (hasFur ? "s dlakom" : "bez dlake") << std::endl;
}