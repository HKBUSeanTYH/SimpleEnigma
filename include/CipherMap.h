#ifndef CIPHERMAP_DEF
#define CIPHERMAP_DEF
#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <ranges>
#include "StringUtil.h"

class CipherMap {
    public:
        CipherMap();
        CipherMap(const std::vector<std::string>&, const bool&);

        //optionally convert an input to its plugged equivalent
        int map(int);
        void process_mappings(const std::vector<std::string>&, const bool&);
        friend std::ostream& operator<<(std::ostream&, CipherMap const&);
    private:
        std::array<int, 26> cipher_mapping;
};
#endif