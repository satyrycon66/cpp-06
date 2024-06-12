#include "B.hpp"
#include <iostream>

B::B() {}

B::B(const B& other) {
    (void)other;
}

B& B::operator=(const B& other) {
    (void)other;
    return *this;
}

void B::identifyPtr() const {
    std::cout << "B" << std::endl;
}