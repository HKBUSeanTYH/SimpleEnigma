#ifndef REFLECTOR_DEF
#define REFLECTOR_DEF
#include <fstream>
#include "CipherMap.h"

class Reflector : public CipherMap {
    public:
        Reflector(const std::vector<std::string>&);
        int map(int) override;
        static Reflector create_reflector(const std::string& path);
        friend std::ostream& operator<<(std::ostream&, Reflector const&);
};
#endif