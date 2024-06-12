#include "A.hpp"
#include <iostream>

A::A() {}

A::A(const A& other) {
    (void)other;
}

A& A::operator=(const A& other) {
    (void)other;
    return *this;
}

void A::identifyPtr() const {
    std::cout << "A" << std::endl;
}
