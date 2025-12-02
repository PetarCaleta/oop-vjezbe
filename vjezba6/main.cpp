#include "container.h"
#include <iostream>
#include <utility>

void pass_by_value(Container c) {
    std::cout << "Inside function, container size: " << c.size() << std::endl;
}

Container return_container() {
    Container temp(2);
    temp.push_back(100);
    temp.push_back(200);
    return temp;
}

int main() {
    Container c1;
    c1.push_back(1);
    c1.push_back(2);
    c1.push_back(3);

    Container c2 = c1;

    Container c3 = std::move(c1);

    pass_by_value(c2);

    Container c4 = return_container();

    for (int i = 0; i < 10; ++i) {
        c4.push_back(i);
    }

    std::cout << "c2 elements:" << std::endl;
    for (size_t i = 0; i < c2.size(); ++i) {
        std::cout << "Index " << i << ": " << c2.at(i) << std::endl;
    }

    std::cout << "c4 elements:" << std::endl;
    for (size_t i = 0; i < c4.size(); ++i) {
        std::cout << "Index " << i << ": " << c4.at(i) << std::endl;
    }

    return 0;
}
