#include "C.hpp"
#include <iostream>

C::C() {}

C::C(const C& other) {
    (void)other;
}

C& C::operator=(const C& other) {
    (void)other;
    return *this;
}

void C::identifyPtr() const {
    std::cout << "C" << std::endl;
}
