#include "Data.hpp"
#include <cstdint>

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
