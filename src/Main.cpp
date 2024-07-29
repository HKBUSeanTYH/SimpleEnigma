#include "Enigma.h"

int main() {
    Enigma enigma {Rotor::create_rotor("../resources/Rotor_1"), Rotor::create_rotor("../resources/Rotor_2"), Rotor::create_rotor("../resources/Rotor_3"), Reflector::create_reflector("../resources/Reflector_1")};
    enigma.input_plugs("A:B B:A C:D D:C");
    std::cout << enigma;
}