#include "Enigma.h"

int main() {
    Rotor one {Rotor::create_rotor("./resources/Rotor_1")};
    Rotor two {Rotor::create_rotor("./resources/Rotor_2")};
    Rotor three {Rotor::create_rotor("./resources/Rotor_3")};
    Reflector ref {Reflector::create_reflector("./resources/Reflector_1")};

    Enigma enigma {one, two, three, ref};
    enigma.input_plugs("A:B B:A C:D D:C");
    std::cout << enigma;
    std::string output {enigma.encipher("Hello World")};

    Enigma receiver {one, two, three, ref};
    receiver.input_plugs("A:B B:A C:D D:C");
    std::cout << receiver;
    receiver.encipher(output);

    //showing effect of ring settings on encipher
    one.set_ring_setting(2);
    two.set_ring_setting(10);
    three.set_ring_setting(6);

    Enigma enigma2 {one, two, three, ref};
    enigma2.input_plugs("A:B B:A C:D D:C");
    std::cout << enigma2;
    std::string output2 {enigma2.encipher("Hello World")};

    Enigma receiver2 {one, two, three, ref};
    receiver2.input_plugs("A:B B:A C:D D:C");
    std::cout << receiver2;
    receiver2.encipher(output2);
}