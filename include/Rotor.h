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
        Rotor(int notch = 0) : notch_pos(notch), rotor_pos(0), ring_setting(0) { 
            default_wiring(this->cipher_mapping); 
            compute_inverse(this->cipher_mapping, this->inverse_mapping); 
        }

        Rotor(int notch, int rotor, int ring, std::vector<std::string> mappings) : notch_pos(notch), rotor_pos(rotor), ring_setting(ring) { 
            process_mappings(this->cipher_mapping, mappings); 
            compute_inverse(this->cipher_mapping, this->inverse_mapping); 
        }
        ~Rotor() {}
    protected:
        const int notch_pos;
        int ring_setting;
        int rotor_pos;

        int encipher(int, int, int, std::array<int,26>&);
        static void process_mappings(std::array<int, 26>&, std::vector<std::string>);
        static void compute_inverse(std::array<int, 26>&, std::array<int, 26>&);
        std::array<int, 26> inverse_mapping;
};
#endif