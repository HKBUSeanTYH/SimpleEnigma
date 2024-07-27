#include "Plugboard.h"

void Plugboard::process_mappings(std::vector<std::string> mappings) {
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        StringUtil::split_into(temp, map, ":");
        if (temp[0].length() == 1 && temp[1].length() == 1) {
            insert_mapping(temp[0][0], temp[1][0]);
        } else {
            std::cout << "Invalid mapping: " << temp[0] << " to " << temp[1] <<"\n";
        }        
    }
}

void Plugboard::insert_mapping(char k, char v) {
    int left = char_to_int(k);
    int right = char_to_int(v);
    //if both are unplugged
    if (this->cipher_mapping[left] == left && this->cipher_mapping[right] == right) {
        this->cipher_mapping[left] = right;
        this->cipher_mapping[right] = left;
    } else {
        throw std::invalid_argument("Invalid plug mapping. Plug has already been mapped.");
    }
}

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