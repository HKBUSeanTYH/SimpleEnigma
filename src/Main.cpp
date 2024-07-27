#include "Enigma.h"

int main() {
    std::array<Rotor, 3> init_rotors {Rotor::create_rotor("../resources/Rotor_1"), Rotor::create_rotor("../resources/Rotor_2"), Rotor::create_rotor("../resources/Rotor_3")};
    Enigma enigma {init_rotors};
    enigma.input_plugs("A:B C:D");
    enigma.print_state();
}