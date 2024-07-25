#ifndef ROTOR_DEF
#define ROTOR_DEF
#include "CipherMap.h"

class Rotor : public CipherMap {
    public:
        int notch_pos;
        
        int map(int) override;
        int inverse_map(int);
        void step_rotor();
        //default constructor
        Rotor(int input = 0) : notch_pos(input) { 
            default_wiring(this->ciphermapping); 
            default_wiring(this->inverseMapping); 
        }
        ~Rotor() {}
    private:
        void compute_inverse_mapping(std::array<int,26>&);
        std::array<int, 26> inverseMapping;
};
#endif