#include "Reflector.h"

Reflector::Reflector(const std::vector<std::string>& mappings) : CipherMap{mappings} { }

int Reflector::map(int input) {
    return this->cipher_mapping[input];
}

Reflector Reflector::create_reflector(const std::string& filePath) {
    std::ifstream inFile(filePath);
    std::string line;
    if (std::getline(inFile, line)) {
        std::transform(line.begin(), line.end(), line.begin(), [](auto c) { return std::toupper(c); });
    } else {
        throw std::invalid_argument("Unable to get mappings");
    }
    std::vector<std::string> mappings = StringUtil::split(line, " ");
    if (mappings.size() != 26) {
        throw std::invalid_argument("Not enough mappings in Rotor file: "+filePath);
    } 
    return Reflector{mappings};
}

std::ostream& operator<<(std::ostream& o, Reflector const& a) {
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