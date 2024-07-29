#ifndef ENIGMA_DEF
#define ENIGMA_DEF
#include <iostream>
#include <string>
#include <vector>
#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"
#include "StringUtil.h"

class Enigma {
    public:
        //member initializer to init plugboard
        Enigma(Rotor one, Rotor two, Rotor three, Reflector ref) : plugboard(), left{one}, centre{two}, right{three}, reflector{ref} { }
        void input_plugs(std::string);
        std::string encipher(std::string);
        friend std::ostream& operator<<(std::ostream& o, Enigma const& a) {
            o << "Plugboard:\n" << a.plugboard << "\nReflector:\n" <<  a.reflector << "\nRotors:\n" << a.left << "\n" << a.centre << "\n" << a.right << "\n";
            return o;
        }
    private:
        Reflector reflector;
        Plugboard plugboard;
        Rotor left;
        Rotor centre;
        Rotor right;
};
#endif