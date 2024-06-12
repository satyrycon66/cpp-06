#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Déclaration des fonctions de Utils.h
Base* generate();
void identify(Base* p);

int main() {
    std::srand(std::time(nullptr)); // Initialisation du générateur de nombres aléatoires
    Base* obj = generate();
    identify(obj);
    obj->identifyRef();
    delete obj; // Libération de la mémoire
    return 0;
}

