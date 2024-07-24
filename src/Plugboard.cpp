#include "Plugboard.h"

void Plugboard::process_plugged_characters(std::tuple<char,char> input) {
    int left = char_to_int(std::get<0>(input));
    int right = char_to_int(std::get<1>(input));
    //if both are unplugged
    if (ciphermapping[left] == left && ciphermapping[right] == right) {
        ciphermapping[left] = right;
        ciphermapping[right] = left;
    } else {
        throw std::invalid_argument("Invalid plug mapping. Plug has already been mapped.");
    }
}

char int_to_char(int i) {
    if (i < 0 || i > 25) {
        throw std::invalid_argument("Invalid int. Accepts 0 - 25");
    }
    return static_cast<char>(i + 65);
}

void Plugboard::print_state() {
    for (int idx = 0; idx < ciphermapping.size(); ++idx) {
        int map_val = ciphermapping[idx];
        if (map_val != idx) {
            char cIdx = int_to_char(idx);
            char cVal = int_to_char(map_val);
            
            std::cout << cIdx << " is mapped to " << cVal << "\n";
        }
    }
}

int Plugboard::map(int idx) {
    return ciphermapping[idx];
}

int Plugboard::char_to_int(char c) {
    if (c < 'A' || c > 'Z') {
        throw std::invalid_argument("Invalid char. Only accepts alphabets");
    }
    return static_cast<int>(c) - 65;
}