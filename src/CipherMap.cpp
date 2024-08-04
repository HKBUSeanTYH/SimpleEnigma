#include "CipherMap.h"

namespace {
    //init to setup default indices of plugboard
    void default_wiring(std::array<int, 26>& arrMapping) {
        for (int idx = 0; idx < arrMapping.size(); ++idx) {
            arrMapping[idx] = idx;
        }
    }

    void init_mappings(std::array<int,26>& source, const std::vector<std::string>& mappings, const bool& is_inverse) {
        std::vector<std::string> temp;
        for (auto& map : mappings) {
            StringUtil::split_into(temp, map, ":");
            if (temp[0].length() == 1 && temp[1].length() == 1) {
                int left {StringUtil::alphabet_to_int(temp[0][0])};
                int right {StringUtil::alphabet_to_int(temp[1][0])};
                if (is_inverse) {
                    source[right] = left;
                } else {
                    source[left] = right;
                }
            } else {
                std::cout << "Invalid mapping: " << temp[0] << " to " << temp[1] <<"\n";
            }        
        }
    }
}

CipherMap::CipherMap() : cipher_mapping{} {
    default_wiring(cipher_mapping);
}

CipherMap::CipherMap(const std::vector<std::string>& mappings, const bool& is_inverse) : cipher_mapping{} {
    default_wiring(this->cipher_mapping);
    init_mappings(this->cipher_mapping, mappings, is_inverse);
}

int CipherMap::map(int idx) {
    return this->cipher_mapping[idx];
}

void CipherMap::process_mappings(const std::vector<std::string>& mappings, const bool& is_inverse) {
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        StringUtil::split_into(temp, map, ":");
        if (temp[0].length() == 1 && temp[1].length() == 1) {
            int left {StringUtil::alphabet_to_int(temp[0][0])};
            int right {StringUtil::alphabet_to_int(temp[1][0])};
            if (is_inverse) {
                this->cipher_mapping[right] = left;
            } else {
                this->cipher_mapping[left] = right;
            }
        } else {
            std::cout << "Invalid mapping: " << temp[0] << " to " << temp[1] <<"\n";
        }        
    }
}

std::ostream& operator<<(std::ostream& o, CipherMap const& a) {
    for (int i = 0; i < a.cipher_mapping.size(); ++i) {
        o << StringUtil::int_to_char(i) << " ";
    }
    o << "\n";
    for (int i = 0; i < a.cipher_mapping.size(); ++i) {
        o << StringUtil::int_to_char(a.cipher_mapping[i]) << " ";
    }
    o << "\n";
    return o;
}