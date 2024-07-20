#ifndef ENIGMA_DEF
#define ENIGMA_DEF
#include <iostream>
#include <string>
#include "Plugboard.h"

class Enigma {
    public:
        //member initializer to init plugboard
        Enigma() : plugboard() {}
        void input_plugs(std::string);
        std::string encipher();
    private:
        Plugboard plugboard;
};
#endif