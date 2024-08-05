#include "CipherMap.h"

namespace {
    //init to setup default indices of plugboard
    void default_wiring(std::array<int, 26>& arrMapping) {
        std::iota(begin(arrMapping), end(arrMapping), 0);
    }
}

CipherMap::CipherMap() : cipher_mapping{} {
    default_wiring(this->cipher_mapping);
}

CipherMap::CipherMap(const std::vector<std::string>& mappings, const bool& is_inverse) : cipher_mapping{} {
    default_wiring(this->cipher_mapping);
    process_mappings(mappings, is_inverse);
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
    std::for_each(begin(a.cipher_mapping), end(a.cipher_mapping), [&o](int i){
        o << StringUtil::int_to_char(i) << " ";
    });
    o << "\n";
    return o;
}