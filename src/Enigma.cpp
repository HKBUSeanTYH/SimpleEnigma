#include "Enigma.h"

Enigma::Enigma(Rotor one, Rotor two, Rotor three, Reflector ref) : reflector{ref}, left{one}, centre{two}, right{three}, plugboard() { }

void Enigma::input_plugs(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), [](auto c) { return std::toupper(c); });
    std::vector<std::string> mappings = StringUtil::split(input, " ");
    plugboard.process_mappings(mappings);
}

std::string Enigma::encipher(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), [](auto c) { return std::toupper(c); });
    std::string output{};
    std::cout << "Input: " << input << "\n";
    for (int i = 0; i < input.size(); ++i) {
        if (is_alphabet(input[i])) {
            char enciphered_char = encipher_helper(input[i]);
            output.push_back(enciphered_char);
        } else {
            output.push_back(input[i]);
        }
    }
    std::cout << "Output: " << output << "\n\n";
    return output;
}

std::ostream& operator<<(std::ostream& o, Enigma const& a) {
    o << "Plugboard:\n" << a.plugboard << "\nReflector:\n" <<  a.reflector << "\nRotors:\n" << a.left << "\n" << a.centre << "\n" << a.right << "\n";
    return o;
}

bool Enigma::is_alphabet(char c) {
    return (c >= 'A' && c <= 'Z');
}

char Enigma::encipher_helper(char c) {
    rotate();
    int i {StringUtil::char_to_int(c)};
    i = plugboard.map(i);

    i = right.map(i);
    i = centre.map(i);
    i = left.map(i);

    i = reflector.map(i);

    i = left.inverse_map(i);
    i = centre.inverse_map(i);
    i = right.inverse_map(i);
    i = plugboard.map(i);
    return StringUtil::int_to_char(i);
}

void Enigma::rotate() {
    if (centre.is_at_notch()) {
        left.turn_over();
        centre.turn_over();
    } else if (right.is_at_notch()) {
        centre.turn_over();
    }
    right.turn_over();
}