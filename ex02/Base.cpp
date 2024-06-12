#include "Base.hpp"
#include <iostream>

Base::Base() {}

Base::Base(const Base& other) {
    (void)other;
}

Base& Base::operator=(const Base& other) {
    (void)other;
    return *this;
}

Base::~Base() {}

void Base::identifyRef() const {
    identifyPtr();
}