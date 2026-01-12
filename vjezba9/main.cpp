#include <iostream>
#include <memory>

#include "ZooSection.h"
#include "ZooKeeper.h"
#include "Lion.h"
#include "Elephant.h"
#include "Dolphin.h"
#include "SeaTurtle.h"

int main() {
    try {
        ZooSection<Animal> section;
        ZooKeeper keeper;

        section.addAnimal(std::make_unique<Lion>("Simba", 5, 190));
        section.addAnimal(std::make_unique<Elephant>("Dumbo", 10, 5000));
        section.addAnimal(std::make_unique<Dolphin>("Flipper", 8, 300));
        section.addAnimal(std::make_unique<SeaTurtle>("Leonardo", 50, 150));

        for (size_t i = 0; i < section.size(); i++) {
            keeper.processAnimal(section.getAnimal(i));
        }

        std::cout << "Ukupna dnevna hrana: "
            << section.totalFood() << " kg" << std::endl;

        std::cout << "Ukupno nahranjenih zivotinja: "
            << ZooKeeper::getTotalAnimalsServed() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Greska: " << e.what() << std::endl;
    }
}