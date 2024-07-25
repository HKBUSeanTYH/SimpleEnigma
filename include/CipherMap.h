#ifndef CIPHERMAP_DEF
#define CIPHERMAP_DEF
#include <array>
#include <stdexcept>

class CipherMap {
    public:
        //optionally convert an input to its plugged equivalent
        virtual int map(int) = 0;
        virtual void insert_mapping(char, char) = 0;
        virtual ~CipherMap() {}
    protected:
        //init to setup default indices of plugboard
        void default_wiring(std::array<int, 26>&);
        std::array<int, 26> ciphermapping;

        //convert a char to its int representation 0-25 and vice versa
        int char_to_int(char);
        char int_to_char(int);
};
#endif