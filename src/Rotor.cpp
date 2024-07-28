#include "Rotor.h"

int Rotor::map(int input) {
    return encipher(input, this->rotor_pos, this->ring_setting, this->cipher_mapping);
}

int Rotor::inverse_map(int input) {
    return encipher(input, this->rotor_pos, this->ring_setting, this->inverse_mapping);
}

void Rotor::set_rotor_pos(int position) {
    this->rotor_pos = (position % 26);
}

void Rotor::set_ring_setting(int steps) {
    this->rotor_pos = steps;
}

bool Rotor::is_at_notch() {
    return (this->rotor_pos == this->notch_pos);
}

void Rotor::turn_over() {
    this->rotor_pos = (this->rotor_pos + 1) % 26;
}

/*
    TODO: look into move semantics. avoid unnecessary copies (even if copy elision may occur).
*/
Rotor Rotor::create_rotor(std::string filePath) {
    std::ifstream inFile(filePath);
    std::string line;
    int notch_pos;
    //read notch
    if (std::getline(inFile, line)) {
        notch_pos = std::stoi(line);
    } else {
        throw std::invalid_argument("Unable to get notch position");
    }
    if (std::getline(inFile, line)) {
        std::transform(line.begin(), line.end(), line.begin(), [](auto c) { return std::toupper(c); });
    } else {
        throw std::invalid_argument("Unable to get mappings");
    }
    std::vector<std::string> mappings = StringUtil::split(line, " ");
    return (mappings.size() == 26) ? Rotor{notch_pos, 0, 0, mappings} : throw std::invalid_argument("Not enough mappings in Rotor file: "+filePath);
}

int Rotor::encipher(int input, int rotor_pos, int ring_setting, std::array<int,26>& mapping) {
    int shift {rotor_pos - ring_setting};
    /*
        ring setting shifts characters N steps forward. With Ring setting B, and Rotor 1
        Z is treated as A
        A is treated as B
        etc ...

        an input of A will go through Z wiring (Z treated as A), Z mapped to J and shifted to K
    */
    return (mapping[(input + shift + 26) % 26] - shift + 26) % 26;
    // input + shift could be negative, so add 26
    // shift needs to be performed both on input and output
    // add another 26 to prevent negatives
}

void Rotor::process_mappings(Rotor* rotor, std::vector<std::string> mappings) {
    std::array<int,26>& source = rotor->cipher_mapping;
    std::vector<std::string> temp;
    for (auto& map : mappings) {
        StringUtil::split_into(temp, map, ":");
        if (temp[0].length() == 1 && temp[1].length() == 1) {
            int left {char_to_int(temp[0][0])};
            int right {char_to_int(temp[1][0])};
            source[left] = right;
        } else {
            std::cout << "Invalid mapping: " << temp[0] << " to " << temp[1] <<"\n";
        }        
    }
}

void Rotor::compute_inverse(Rotor* rotor) {
    std::array<int,26>& source = rotor->cipher_mapping;
    std::array<int,26>& dest = rotor->inverse_mapping;
    for (int i = 0; i < source.size(); ++i) {
        dest[source[i]] = i; //get the value at index i of source array, treat it as index of inverse, and place source index as value
    }
}