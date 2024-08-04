#include "Rotor.h"

//limit linkage to inside translation unit only
//allows compiler to optimize more aggressively + make linking simpler
namespace {
    int encipher(int input, int rotor_pos, int ring_setting, CipherMap& mapping) {
        int shift {rotor_pos - ring_setting};
        /*
            ring setting shifts characters N steps forward. With Ring setting B, and Rotor 1
            Z is treated as A
            A is treated as B
            etc ...

            an input of A will go through Z wiring (Z treated as A), Z mapped to J and shifted to K

            rotor 1 in Ring setting A:
            A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
        --> E K M F L G D Q V Z N T O W Y H X U S P A I B R C J (the inner wiring is shifted forward)

            rotor 1 in Ring setting B:
            A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
        --> J E K M F L G D Q V Z N T O W Y H X U S P A I B R C (wiring wraps around)
        */
        return (mapping.map((input + shift + 26) % 26) - shift + 26) % 26;
        // input + shift could be negative, so add 26
        // shift needs to be performed both on input and output
        // add another 26 to prevent negatives
    }
}

Rotor::Rotor(int notch, int rotor, int ring, std::vector<std::string>& mappings) : notch_pos(notch), rotor_pos(rotor), ring_setting(ring), regular_mapping{mappings, false}, inverse_mapping{mappings, true} { 
    // //https://stackoverflow.com/a/445135/16034206 - passing 'this' to a static function inside constructor
}

int Rotor::map(int input) {
    return encipher(input, this->rotor_pos, this->ring_setting, this->regular_mapping);
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
    o << a.regular_mapping;
    return o;
}