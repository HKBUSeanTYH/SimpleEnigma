#ifndef PLUGBOARD_DEF
#define PLUGBOARD_DEF
#include <tuple>
#include <stdexcept>
#include <iostream>
#include "CipherMap.h"

class Plugboard : public CipherMap{
    public:
        //process user assigned plugs
        void process_plugged_characters(std::tuple<char,char>);
        int map(int) override;
        void print_state();
        //plugboard constructor that initializes the default wiring for plugboard
        Plugboard() { default_wiring(); }
        ~Plugboard() {}
    private:
        //convert a char to its int representation 0-25
        int char_to_int(char);
        char int_to_char(int i);
};
#endif