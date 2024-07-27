#include "Rotor.h"

int Rotor::map(int input) {
    return this->ciphermapping[handle_rotor_shift(input)];
}

int Rotor::inverse_map(int input) {
    return this->inverseMapping[handle_rotor_shift(input)];
}

void Rotor::set_rotor_pos(int position) {
    this->rotor_pos = (position % 26);
}

bool Rotor::is_at_notch() {
    return (this->rotor_pos == this->notch_pos);
}

void Rotor::turn_over() {
    this->rotor_pos = (this->rotor_pos + 1) % 26;
}

int Rotor::handle_rotor_shift(int input) {
    return (input + this->rotor_pos) % 26;
}

void compute_inverse(std::array<int,26>& source, std::array<int,26>& inverse) {
    for (int i = 0; i < source.size(); ++i) {
        inverse[source[i]] = i; //get the value at index i of source array, treat it as index of inverse, and place source index as value
    }
}