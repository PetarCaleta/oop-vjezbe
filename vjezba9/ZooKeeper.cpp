#include "ZooKeeper.h"
#include <iostream>

int ZooKeeper::totalAnimalsServed = 0;

void ZooKeeper::processAnimal(Animal* animal) {
    if (!animal) return;
    std::cout << "Species: " << animal->getSpecies()
        << ", Name: " << animal->getName()
        << ", Food: " << animal->getDailyFood() << " kg" << std::endl;
    totalAnimalsServed++;
}

int ZooKeeper::getTotalAnimalsServed() {
    return totalAnimalsServed;
}