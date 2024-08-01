#ifndef CIPHERMAP_DEF
#define CIPHERMAP_DEF
#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "StringUtil.h"

class CipherMap {
    protected:
        //optionally convert an input to its plugged equivalent
        virtual int map(int) = 0;
        // virtual ~CipherMap() {}

        CipherMap();
        CipherMap(const std::vector<std::string>&);
        
        std::array<int, 26> cipher_mapping;

        //init to setup default indices of plugboard
        static void default_wiring(std::array<int, 26>&);
        static void process_mappings(std::array<int,26>&, const std::vector<std::string>&);
};
#endif