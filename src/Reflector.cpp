#include "Reflector.h"

Reflector::Reflector(const std::vector<std::string>& mappings) : regular_mapping{mappings, false} { }

int Reflector::map(int input) {
    return this->regular_mapping.map(input);
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
    o << a.regular_mapping;
    return o;
}