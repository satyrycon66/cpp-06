#include "Data.hpp"
#include <iostream>

extern uintptr_t serialize(Data* ptr);
extern Data* deserialize(uintptr_t raw);

int main() {
    Data data;
    data.x = 10;
    data.y = 3.14f;
    data.z = 'A';

    uintptr_t serialized = serialize(&data);
    Data* deserialized = deserialize(serialized);

    // Vérification
    if (deserialized == &data) {
        std::cout << "La désérialisation a réussi. Pointeur d'origine récupéré." << std::endl;
    } else {
        std::cout << "Erreur : La désérialisation a échoué." << std::endl;
    }

    return 0;
}