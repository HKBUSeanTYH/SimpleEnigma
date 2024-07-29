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

        static void compute_inverse(Rotor*);

        static Rotor create_rotor(std::string path);
        Rotor(int notch = 0) : notch_pos(notch), rotor_pos(0), ring_setting(0) {
            compute_inverse(this); 
        }

        Rotor(int notch, int rotor, int ring, std::vector<std::string> mappings) : notch_pos(notch), rotor_pos(rotor), ring_setting(ring) { 
            //https://stackoverflow.com/a/445135/16034206 - passing 'this' to a static function inside constructor
            CipherMap::process_mappings(this, mappings); 
            compute_inverse(this); 
        }
        ~Rotor() {}

        friend std::ostream& operator<<(std::ostream& o, Rotor const& a) {
            for (int i = 0; i < a.cipher_mapping.size(); ++i) {
                o << int_to_char(i) << " ";
            }
            o << "\n";
            for (int i = 0; i < a.cipher_mapping.size(); ++i) {
                o << int_to_char(a.cipher_mapping[i]) << " ";
            }
            o << "\n";
            return o;
        }
    protected:
        const int notch_pos;
        int ring_setting;
        int rotor_pos;

        int encipher(int, int, int, std::array<int,26>&);
        std::array<int, 26> inverse_mapping;
};
#endif