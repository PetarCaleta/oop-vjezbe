#include "container.h"

Container::Container(size_t initial_capacity)
    : data(nullptr), _size(0), _capacity(initial_capacity)
{
    if (_capacity > 0) {
        data = new int[_capacity];
    }
    std::cout << "Container created with capacity " << _capacity << std::endl;
}

Container::Container(const Container& other)
    : data(nullptr), _size(other._size), _capacity(other._capacity)
{
    if (_capacity > 0) {
        data = new int[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            data[i] = other.data[i];
        }
    }
    std::cout << "Container copied (copy constructor)" << std::endl;
}

Container::Container(Container&& other) noexcept
    : data(other.data), _size(other._size), _capacity(other._capacity)
{
    other.data = nullptr;
    other._size = 0;
    other._capacity = 0;
    std::cout << "Container moved (move constructor)" << std::endl;
}

Container::~Container() {
    delete[] data;
    std::cout << "Container destroyed" << std::endl;
}

void Container::push_back(int value) {
    if (_size >= _capacity) {
        size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
        int* new_data = new int[new_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        _capacity = new_capacity;
        std::cout << "Container reallocated to capacity " << _capacity << std::endl;
    }
    data[_size++] = value;
}

size_t Container::size() const {
    return _size;
}

size_t Container::capacity() const {
    return _capacity;
}

int& Container::at(size_t index) {
    if (index >= _size) throw std::out_of_range("Index out of range");
    return data[index];
}

const int& Container::at(size_t index) const {
    if (index >= _size) throw std::out_of_range("Index out of range");
    return data[index];
}

void Container::clear() {
    _size = 0;
    std::cout << "Container cleared" << std::endl;
}
