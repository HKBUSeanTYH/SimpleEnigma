#ifndef ROTOR_DEF
#define ROTOR_DEF
#include <iostream>
#include <fstream>
#include "CipherMap.h"
#include "StringUtil.h"

class Rotor : public CipherMap {
    public:     
        int map(int) override;
        int inverse_map(int);

        void set_ring_setting(int);
        void set_rotor_pos(int);
        bool is_at_notch();
        void turn_over();

        static Rotor create_rotor(std::string path);
        Rotor(int notch = 0, int rotor = 0, int ring = 0) : notch_pos(notch), rotor_pos(rotor), ring_setting(ring) { 
            default_wiring(this->cipher_mapping); 
            compute_inverse(this->cipher_mapping, this->inverse_mapping); 
        }
        Rotor(int notch, int rotor, int ring, std::string input) : notch_pos(notch), rotor_pos(rotor), ring_setting(ring) { 
            std::transform(input.begin(), input.end(), input.begin(), [](auto c) { return std::toupper(c); });
            std::vector<std::string> mappings = StringUtil::split(input, " ");
            process_mappings(this->cipher_mapping, mappings);
            compute_inverse(this->cipher_mapping, this->inverse_mapping);
        }
        ~Rotor() {}
    private:
        const int notch_pos;
        int ring_setting;
        int rotor_pos;

        int encipher(int, int, int, std::array<int,26>&);
        static void compute_inverse(std::array<int,26>&, std::array<int,26>&);
        std::array<int, 26> inverse_mapping;
};
#endif