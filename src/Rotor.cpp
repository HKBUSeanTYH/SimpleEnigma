#include "Rotor.h"

int Rotor::map(int input) {
    return encipher(input, this->rotor_pos, this->ring_setting, this->cipher_mapping);
}

int Rotor::inverse_map(int input) {
    return encipher(input, this->rotor_pos, this->ring_setting, this->inverse_mapping);
}

void Rotor::set_rotor_pos(int position) {
    this->rotor_pos = (position % 26);
}

void Rotor::set_ring_setting(int steps) {
    this->rotor_pos = steps;
}

bool Rotor::is_at_notch() {
    return (this->rotor_pos == this->notch_pos);
}

void Rotor::turn_over() {
    this->rotor_pos = (this->rotor_pos + 1) % 26;
}

int Rotor::encipher(int input, int rotor_pos, int ring_setting, std::array<int,26>& mapping) {
    int shift {rotor_pos - ring_setting};
    /*
        ring setting shifts characters N steps forward. With Ring setting B, and Rotor 1
        Z is treated as A
        A is treated as B
        etc ...

        an input of A will go through Z wiring (Z treated as A), Z mapped to J and shifted to K
    */
    return (mapping[(input + shift + 26) % 26] - shift + 26) % 26;
    // input + shift could be negative, so add 26
    // shift needs to be performed both on input and output
    // add another 26 to prevent negatives
}

void compute_inverse(std::array<int,26>& source, std::array<int,26>& inverse) {
    for (int i = 0; i < source.size(); ++i) {
        inverse[source[i]] = i; //get the value at index i of source array, treat it as index of inverse, and place source index as value
    }
}