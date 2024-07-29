#include "Plugboard.h"

int Plugboard::map(int idx) {
    return this->cipher_mapping[idx];
}


void Plugboard::process_mappings(std::vector<std::string> mappings) {
    CipherMap::process_mappings(this, mappings);
}