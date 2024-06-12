#ifndef BASE_H
#define BASE_H

class Base {
public:
    Base(); // Constructeur par défaut
    Base(const Base& other); // Constructeur de copie
    Base& operator=(const Base& other); // Affectation par copie
    virtual ~Base(); // Destructeur par défaut
    virtual void identifyPtr() const = 0;
    void identifyRef() const;
};

#endif // BASE_H

