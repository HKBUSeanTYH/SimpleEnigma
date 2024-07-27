#ifndef PLUGBOARD_DEF
#define PLUGBOARD_DEF
#include <iostream>
#include <vector>
#include "StringUtil.h"
#include "CipherMap.h"

class Plugboard : public CipherMap{
    public:
        //process user assigned plugs
        void process_mappings(std::vector<std::string>) override;
        int map(int) override;
        void print_state();
        //plugboard constructor that initializes the default wiring for plugboard
        Plugboard() { default_wiring(this->cipher_mapping); }
        ~Plugboard() {}
    private:
        void insert_mapping(char, char) override;
};
#endif