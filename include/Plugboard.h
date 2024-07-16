#ifndef PLUGBOARD_DEF
#define PLUGBOARD_DEF
#include <string>
#include "CipherMap.h"

class Plugboard : public CipherMap{
    public:
        //get user assigned plugs
        void get_plugged_characters(std::string);
    private:
        //convert a char to its int representation 0-25
        int char_to_int(char);
};
#endif