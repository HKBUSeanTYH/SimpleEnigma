#ifndef PLUGBOARD_DEF
#define PLUGBOARD_DEF
#include <iostream>
#include "CipherMap.h"

class Plugboard : public CipherMap{
    public:
        //process user assigned plugs
        void process_plugged_characters(char, char);
        int map(int) override;
        void print_state();
        //plugboard constructor that initializes the default wiring for plugboard
        Plugboard() { default_wiring(this->ciphermapping); }
        ~Plugboard() {}
};
#endif