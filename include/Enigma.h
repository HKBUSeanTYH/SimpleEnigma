#ifndef ENIGMA_DEF
#define ENIGMA_DEF
#include "Plugboard.h"
class Enigma {
    public:
        void input_plugs();
        std::string encipher();
    private:
        Plugboard plugboard;
};
#endif