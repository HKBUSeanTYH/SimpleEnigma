#include "CipherMap.h"

void CipherMap::default_wiring(std::array<int, 26>& arrMapping) {
    for (int idx = 0; idx < arrMapping.size(); ++idx) {
        arrMapping[idx] = idx;
    }
}

char CipherMap::int_to_char(int i) {
    if (i < 0 || i > 25) {
        throw std::invalid_argument("Invalid int. Accepts 0 - 25");
    }
    return static_cast<char>(i + 65);
}

int CipherMap::char_to_int(char c) {
    if (c < 'A' || c > 'Z') {
        throw std::invalid_argument("Invalid char. Only accepts alphabets");
    }
    return static_cast<int>(c) - 65;
}

void CipherMap::process_mappings(std::array<int, 26>& dest, std::vector<std::string> mappings) {
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        StringUtil::split_into(temp, map, ":");
        if (temp[0].length() == 1 && temp[1].length() == 1) {
            insert_mapping(dest, temp[0][0], temp[1][0]);
        } else {
            std::cout << "Invalid mapping: " << temp[0] << " to " << temp[1] <<"\n";
        }        
    }
}

void CipherMap::insert_mapping(std::array<int, 26>& dest, char k, char v) {
    int left = char_to_int(k);
    int right = char_to_int(v);
    //if both are unplugged
    if (dest[left] == left && dest[right] == right) {
        dest[left] = right;
        dest[right] = left;
    } else {
        throw std::invalid_argument("Invalid plug mapping. Plug has already been mapped.");
    }
}