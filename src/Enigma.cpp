#include "Enigma.h"

void Enigma::input_plugs(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), [](auto c) { return std::toupper(c); });
    std::vector<std::string> mappings = StringUtil::split(input, " ");
    plugboard.process_mappings(mappings);
}

std::string Enigma::encipher(std::string input) {
    return std::string("temp");
}

void Enigma::print_state() {
    plugboard.print_state();
}