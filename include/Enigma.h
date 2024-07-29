#ifndef ENIGMA_DEF
#define ENIGMA_DEF
#include <iostream>
#include <string>
#include <vector>
#include "Plugboard.h"
#include "Rotor.h"
#include "StringUtil.h"

class Enigma {
    public:
        //member initializer to init plugboard
        Enigma(Rotor one, Rotor two, Rotor three) : plugboard(), left{one}, centre{two}, right{three} { }
        void input_plugs(std::string);
        std::string encipher(std::string);
        friend std::ostream& operator<<(std::ostream& o, Enigma const& a) {
            o << a.plugboard << "\nRotors:\n" << a.left << "\n" << a.centre << "\n" << a.right << "\n";
            return o;
        }
    private:
        Plugboard plugboard;
        Rotor left;
        Rotor centre;
        Rotor right;
};
#endif