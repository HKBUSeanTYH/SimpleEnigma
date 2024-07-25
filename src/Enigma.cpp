#include "Enigma.h"

void Enigma::input_plugs(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), [](auto c) { return std::toupper(c); });
    std::vector<std::string> mappings = StringUtil::split(input, " ");
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        StringUtil::split_into(temp, map, ":");
        if (temp[0].length() == 1 && temp[1].length() == 1) {
            plugboard.process_plugged_characters(temp[0][0], temp[1][0]);
        } else {
            std::cout << "Invalid mapping: " << temp[0] << " to " << temp[1] <<"\n";
        }        
    }
}

std::string Enigma::encipher(std::string input) {
    return std::string("temp");
}

void Enigma::print_state() {
    plugboard.print_state();
}