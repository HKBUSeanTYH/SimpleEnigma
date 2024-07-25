#include "Plugboard.h"

void Plugboard::process_plugged_characters(char left, char right) {
    //if both are unplugged
    if (ciphermapping[left] == left && ciphermapping[right] == right) {
        ciphermapping[left] = right;
        ciphermapping[right] = left;
    } else {
        throw std::invalid_argument("Invalid plug mapping. Plug has already been mapped.");
    }
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