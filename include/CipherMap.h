#ifndef CIPHERMAP_DEF
#define CIPHERMAP_DEF
#include <array>
#include <vector>
#include <string>
#include <stdexcept>

class CipherMap {
    protected:
        //optionally convert an input to its plugged equivalent
        virtual int map(int) = 0;
        virtual void insert_mapping(char, char) = 0;
        virtual void process_mappings(std::vector<std::string>) = 0;
        virtual ~CipherMap() {}

        //init to setup default indices of plugboard
        static void default_wiring(std::array<int, 26>&);
        std::array<int, 26> ciphermapping;

        //convert a char to its int representation 0-25 and vice versa
        static int char_to_int(char);
        static char int_to_char(int);
};
#endif