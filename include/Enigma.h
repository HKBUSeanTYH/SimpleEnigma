#ifndef ENIGMA_DEF
#define ENIGMA_DEF
#include <iostream>
#include <string>
#include <vector>
#include "Plugboard.h"
#include "StringUtil.h"

class Enigma {
    public:
        //member initializer to init plugboard
        Enigma() : plugboard() {}
        void input_plugs(std::string);
        std::string encipher(std::string);
        void print_state();
    private:
        Plugboard plugboard;
};
#endif