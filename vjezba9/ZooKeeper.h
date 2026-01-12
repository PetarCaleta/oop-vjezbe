#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H

#include "Animal.h"

class ZooKeeper {
    static int totalAnimalsServed;

public:
    void processAnimal(Animal* animal);
    static int getTotalAnimalsServed();
};

#endif