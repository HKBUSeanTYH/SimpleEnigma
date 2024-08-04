#ifndef PLUGBOARD_DEF
#define PLUGBOARD_DEF
#include "CipherMap.h"

class Plugboard {
    public:
        int map(int);
        void process_mappings(const std::vector<std::string>&);
        friend std::ostream& operator<<(std::ostream&, Plugboard const&);
    private:
        CipherMap regular_mapping;
};
#endif