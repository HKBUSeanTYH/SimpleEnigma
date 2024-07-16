#ifndef PLUGBOARD_DEF
#define PLUGBOARD_DEF
#include <string>
class Plugboard {
    public:
        //get user assigned plugs
        void get_plugged_characters(std::string);
        //optionally convert an input to its plugged equivalent
        void forward(int);
    private:
        //init to setup default indices of plugboard
        void default_wiring();
        //convert a char to its int representation 0-25
        int char_to_int(char);
};
#endif