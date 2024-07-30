#include "CipherMap.h"

void CipherMap::default_wiring(std::array<int, 26>& arrMapping) {
    for (int idx = 0; idx < arrMapping.size(); ++idx) {
        arrMapping[idx] = idx;
    }
}

void CipherMap::process_mappings(CipherMap* ciphermap, std::vector<std::string> mappings) {
    std::array<int,26>& source = ciphermap->cipher_mapping;
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        StringUtil::split_into(temp, map, ":");
        if (temp[0].length() == 1 && temp[1].length() == 1) {
            int left {StringUtil::alphabet_to_int(temp[0][0])};
            int right {StringUtil::alphabet_to_int(temp[1][0])};
            source[left] = right;
        } else {
            std::cout << "Invalid mapping: " << temp[0] << " to " << temp[1] <<"\n";
        }        
    }
}