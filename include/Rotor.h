#ifndef ROTOR_DEF
#define ROTOR_DEF
#include "CipherMap.h"

class Rotor : public CipherMap {
    public:     
        int map(int) override;
        int inverse_map(int);

        void set_rotor_pos(int);
        bool is_at_notch();
        void turn_over();

        Rotor(int notch = 0, int rotor = 0) : notch_pos(notch), rotor_pos(rotor) { 
            default_wiring(this->ciphermapping); 
            compute_inverse(this->ciphermapping, this->inverseMapping); 
        }
        ~Rotor() {}
    private:
        const int notch_pos;
        int rotor_pos;

        int handle_rotor_shift(int);
        static void compute_inverse(std::array<int,26>&, std::array<int,26>&);
        std::array<int, 26> inverseMapping;
};
#endif