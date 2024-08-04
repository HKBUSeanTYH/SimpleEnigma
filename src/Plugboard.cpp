#include "Plugboard.h"

int Plugboard::map(int idx) {
    return this->regular_mapping.map(idx);
}

void Plugboard::process_mappings(const std::vector<std::string>& mappings) {
    this->regular_mapping.process_mappings(mappings, false);
}

std::ostream& operator<<(std::ostream& o, Plugboard const& a) {
    o << a.regular_mapping;
    return o;
}