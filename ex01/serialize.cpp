#include "Data.hpp"
#include <cstdint>

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
