#pragma once
#include <stdint.h>
#include <string>
#include <vector>
#include "proton/variant.hpp"

#define PRINTS(msg, ...) printf("[SERVER]: " msg, __VA_ARGS__);
#define PRINTC(msg, ...) printf("[CLIENT]: " msg, __VA_ARGS__);
#define MALLOC(type, ...) (type*)(malloc(sizeof(type) __VA_ARGS__))
#define get_packet_type(packet) (packet->dataLength > 3 ? *packet->data : 0)
#define DO_ONCE            \
    ([]() {                \
        static char o = 0; \
        return !o && ++o;  \
    }())
#ifdef _WIN32
#define INLINE __forceinline
#else //for gcc/clang
#define INLINE __attribute__((always_inline))
#endif

namespace utils {
    bool is_number(const std::string& s);
} // namespace utils

bool utils::is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin() + (*s.data() == '-' ? 1 : 0), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}
