#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <stdexcept>

class Container {
private:
    int* data;
    size_t _size;
    size_t _capacity;

public:
    Container(size_t initial_capacity = 0);
    Container(const Container& other);
    Container(Container&& other) noexcept;
    ~Container();

    void push_back(int value);
    size_t size() const;
    size_t capacity() const;
    int& at(size_t index);
    const int& at(size_t index) const;
    void clear();
};

#endif
