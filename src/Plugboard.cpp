#include "Plugboard.h"

void Plugboard::print_state() {
    for (int idx = 0; idx < this->cipher_mapping.size(); ++idx) {
        int map_val = this->cipher_mapping[idx];
        if (map_val != idx) {
            char cIdx = int_to_char(idx);
            char cVal = int_to_char(map_val);
            
            std::cout << cIdx << " is mapped to " << cVal << "\n";
        }
    }
}

int Plugboard::map(int idx) {
    return this->cipher_mapping[idx];
}

void Plugboard::process_mappings(std::vector<std::string> mappings) {
    CipherMap::process_mappings(this->cipher_mapping, mappings);
}