#ifndef ROTOR_DEF
#define ROTOR_DEF
#include <iostream>
#include <fstream>
#include <filesystem>
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
        std::string get_mappings();

        static void compute_inverse(const std::array<int,26>&, std::array<int,26>&);
        static Rotor create_rotor(std::string path);
        friend std::ostream& operator<<(std::ostream&, Rotor const&);
    private:
        int notch_pos;
        int ring_setting;
        int rotor_pos;

        Rotor() = delete;
        Rotor(int, int, int, std::vector<std::string>&);

        int encipher(int, int, int, std::array<int,26>&);
        std::array<int, 26> inverse_mapping;
};
#endif