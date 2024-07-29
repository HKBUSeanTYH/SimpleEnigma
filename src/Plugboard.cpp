#include "Plugboard.h"

int Plugboard::map(int idx) {
    return this->cipher_mapping[idx];
}


void Plugboard::process_mappings(std::vector<std::string> mappings) {
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        StringUtil::split_into(temp, map, ":");
        if (temp[0].length() == 1 && temp[1].length() == 1) {
            int left {char_to_int(temp[0][0])};
            int right {char_to_int(temp[1][0])};
            this->cipher_mapping[left] = right;
            this->cipher_mapping[right] = left;
        } else {
            std::cout << "Invalid mapping: " << temp[0] << " to " << temp[1] <<"\n";
        }        
    }
}