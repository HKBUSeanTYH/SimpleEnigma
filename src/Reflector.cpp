#include "Reflector.h"

int Reflector::map(int input) {
    return this->cipher_mapping[input];
}

Reflector Reflector::create_reflector(std::string filePath) {
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