#include "Enigma.h"

int main() {
    Rotor one {Rotor::create_rotor("../resources/Rotor_1")};
    Rotor two {Rotor::create_rotor("../resources/Rotor_2")};
    Rotor three {Rotor::create_rotor("../resources/Rotor_3")};
    Reflector ref {Reflector::create_reflector("../resources/Reflector_1")};

    Enigma enigma {one, two, three, ref};
    enigma.input_plugs("A:B B:A C:D D:C");
    std::cout << enigma;

    std::string output {enigma.encipher("Hello World")};
    std::cout << output << "\n\n";

    Enigma receiver {one, two, three, ref};
    receiver.input_plugs("A:B B:A C:D D:C");
    std::cout << receiver;
    std::cout << receiver.encipher(output);
}