#ifndef PLUGBOARD_DEF
#define PLUGBOARD_DEF
#include "CipherMap.h"

class Plugboard : public CipherMap{
    public:
        int map(int) override;
        void process_mappings(std::vector<std::string>);
        void print_state();
        ~Plugboard() {}
};
#endif