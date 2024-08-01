#include "Plugboard.h"

int Plugboard::map(int idx) {
    return this->cipher_mapping[idx];
}

void Plugboard::process_mappings(std::vector<std::string> mappings) {
    CipherMap::process_mappings(this->cipher_mapping, mappings);
}

std::ostream& operator<<(std::ostream& o, Plugboard const& a) {
    for (int idx = 0; idx < a.cipher_mapping.size(); ++idx) {
        int map_val = a.cipher_mapping[idx];
        if (map_val != idx) {
            char cIdx = StringUtil::int_to_char(idx);
            char cVal = StringUtil::int_to_char(map_val);
            
            o << cIdx << " is mapped to " << cVal << "\n";
        }
    }
    return o;
}