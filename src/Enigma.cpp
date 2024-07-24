#include "Enigma.h"

void Enigma::input_plugs(std::string input) {
    std::vector<std::string> mappings = split(input, " ");
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        split(temp, map, ":");
        plugboard.process_plugged_characters({temp[0][0], temp[1][0]});
    }
}

std::string Enigma::encipher(std::string input) {
    return std::string("temp");
}

void Enigma::print_state() {
    plugboard.print_state();
}