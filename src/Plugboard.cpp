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

int Plugboard::map(int idx) {
    return ciphermapping[idx];
}

int Plugboard::char_to_int(char c) {
    return 0;
}