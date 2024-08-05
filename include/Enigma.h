#ifndef ENIGMA_DEF
#define ENIGMA_DEF
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"
#include "StringUtil.h"

class Enigma {
    public:
        //member initializer to init plugboard
        Enigma(Rotor, Rotor, Rotor, Reflector);
        void input_plugs(std::string);
        std::string encipher(std::string);
        friend std::ostream& operator<<(std::ostream&, Enigma const&);
    private:
        Reflector reflector;
        Rotor left;
        Rotor centre;
        Rotor right;
        Plugboard plugboard;

        char encipher_helper(char);
        void rotate();
};
#endif