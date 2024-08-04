#ifndef REFLECTOR_DEF
#define REFLECTOR_DEF
#include <fstream>
#include "CipherMap.h"

class Reflector {
    public:
        Reflector(const std::vector<std::string>&);
        int map(int);
        static Reflector create_reflector(const std::string& path);
        friend std::ostream& operator<<(std::ostream&, Reflector const&);
    private:
        CipherMap regular_mapping;
};
#endif