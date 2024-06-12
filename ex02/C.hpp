#ifndef C_H
#define C_H

#include "Base.hpp"

class C : public Base {
public:
    C(); // Constructeur par défaut
    C(const C& other); // Constructeur de copie
    C& operator=(const C& other); // Affectation par copie
    void identifyPtr() const;
};

#endif // C_H
