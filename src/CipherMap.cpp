#include "CipherMap.h"

void CipherMap::default_wiring(std::array<int, 26>& arrMapping) {
    for (int idx = 0; idx < arrMapping.size(); ++idx) {
        arrMapping[idx] = idx;
    }
}

char CipherMap::int_to_char(int i) {
    if (i < 0 || i > 25) {
        throw std::invalid_argument("Invalid int. Accepts 0 - 25");
    }
    return static_cast<char>(i + 65);
}

int CipherMap::char_to_int(char c) {
    if (c < 'A' || c > 'Z') {
        throw std::invalid_argument("Invalid char. Only accepts alphabets");
    }
    return static_cast<int>(c) - 65;
}