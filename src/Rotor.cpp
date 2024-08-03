#include "Rotor.h"

//limit linkage to inside translation unit only
//allows compiler to optimize more aggressively + make linking simpler
namespace {
    void compute_inverse(const std::array<int,26>& source, std::array<int,26>& dest) {
        for (int i = 0; i < source.size(); ++i) {
            dest[source[i]] = i; //get the value at index i of source array, treat it as index of inverse, and place source index as value
        }
    }

    int encipher(int input, int rotor_pos, int ring_setting, std::array<int,26>& mapping) {
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
}

Rotor::Rotor(int notch, int rotor, int ring, std::vector<std::string>& mappings) : notch_pos(notch), rotor_pos(rotor), ring_setting(ring), CipherMap{mappings} { 
    //https://stackoverflow.com/a/445135/16034206 - passing 'this' to a static function inside constructor
    compute_inverse(this->cipher_mapping, this->inverse_mapping); 
}

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

std::string Rotor::get_mappings() {
    std::string out;
    for (int i = 0; i < cipher_mapping.size(); ++i) {
        out.append(StringUtil::int_to_char(i)+" ");
    }
    out.append("\n");
    for (int i = 0; i < cipher_mapping.size(); ++i) {
        out.append(StringUtil::int_to_char(cipher_mapping[i])+" ");
    }
    out.append("\n");
    for (int i = 0; i < cipher_mapping.size(); ++i) {
        out.append(StringUtil::int_to_char(i)+" ");
    }
    out.append("\n");
    for (int i = 0; i < cipher_mapping.size(); ++i) {
        out.append(StringUtil::int_to_char(inverse_mapping[i])+" ");
    }
    return out.append("\n");
}

/*
    TODO: look into move semantics. avoid unnecessary copies (even if copy elision may occur).
*/
Rotor Rotor::create_rotor(std::string file_path) {
    if (!std::filesystem::exists(file_path)) {
        throw std::invalid_argument("File ("+file_path+") does not exist.");
    }
    std::ifstream inFile(file_path);
    std::string line;
    int notch_pos;
    //read notch
    if (std::getline(inFile, line)) {
        notch_pos = std::stoi(line);
    } else {
        throw std::runtime_error("Unable to get notch position");
    }
    if (std::getline(inFile, line)) {
        std::transform(line.begin(), line.end(), line.begin(), [](auto c) { return std::toupper(c); });
    } else {
        throw std::runtime_error("Unable to get mappings");
    }
    std::vector<std::string> mappings = StringUtil::split(line, " ");
    return (mappings.size() == 26) ? Rotor{notch_pos, 0, 0, mappings} : throw std::runtime_error("Not enough mappings in Rotor file: "+file_path);
}

std::ostream& operator<<(std::ostream& o, Rotor const& a) {
    o << "Positions:\n";
    o << "Notch: " << a.notch_pos << " Rotor pos: " << a.rotor_pos << " Ring Setting: " << a.ring_setting << "\n";
    return o;
}