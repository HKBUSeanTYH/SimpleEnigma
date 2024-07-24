#include "Enigma.h"

void Enigma::input_plugs(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), [](auto c) { return std::toupper(c); });
    std::vector<std::string> mappings = split(input, " ");
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        split_into(temp, map, ":");
        plugboard.process_plugged_characters({temp[0][0], temp[1][0]});
    }
}

std::string Enigma::encipher(std::string input) {
    return std::string("temp");
}

void Enigma::print_state() {
    plugboard.print_state();
}