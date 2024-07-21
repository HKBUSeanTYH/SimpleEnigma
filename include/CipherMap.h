#ifndef CIPHERMAP_DEF
#define CIPHERMAP_DEF
#include <array>

class CipherMap {
    public:
        //optionally convert an input to its plugged equivalent
        virtual int map(int) = 0;
        virtual ~CipherMap() {}
    protected:
        //init to setup default indices of plugboard
        void default_wiring();
        std::array<int, 26> ciphermapping;
};
#endif