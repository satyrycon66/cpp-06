#ifndef A_H
#define A_H

#include "Base.hpp"

class A : public Base {
public:
    A();
    A(const A& other); // Constructeur de copie
    A& operator=(const A& other); // Affectation par copie
    void identifyPtr() const;
};

#endif // A_H
