#ifndef B_H
#define B_H

#include "Base.hpp"

class B : public Base {
public:
    B(); // Constructeur par défaut
    B(const B& other); // Constructeur de copie
    B& operator=(const B& other); // Affectation par copie
    void identifyPtr() const;
};

#endif // B_H

