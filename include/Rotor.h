#ifndef ROTOR_DEF
#define ROTOR_DEF
#include <iostream>
#include <fstream>
#include <filesystem>
#include "CipherMap.h"
#include "StringUtil.h"

class Rotor {
    private:
        int notch_pos;
        int ring_setting;
        int rotor_pos;

        Rotor(int, int, int, std::vector<std::string>&);

        CipherMap inverse_mapping;
        CipherMap regular_mapping;
    public:
        int map(int);
        int inverse_map(int);

        void set_ring_setting(int);
        void set_rotor_pos(int);
        bool is_at_notch();
        void turn_over();

        // static void compute_inverse(const std::array<int,26>&, std::array<int,26>&);
        static Rotor create_rotor(std::string path);
        friend std::ostream& operator<<(std::ostream&, Rotor const&);
};
#endif