#ifndef REFLECTOR_DEF
#define REFLECTOR_DEF
#include <fstream>
#include "CipherMap.h"

class Reflector {
    public:
        int map(int);
        static Reflector create_reflector(const std::string& path);
        friend std::ostream& operator<<(std::ostream&, Reflector const&);
    private:
        CipherMap regular_mapping;
        Reflector(const std::vector<std::string>&);
};
#endif