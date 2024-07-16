#ifndef CIPHERMAP_DEF
#define CIPHERMAP_DEF
#include <iterator>

class CipherMap {
    public:
        //optionally convert an input to its plugged equivalent
        virtual void forward(int) = 0;
        virtual ~CipherMap() {}
    private:
        //init to setup default indices of plugboard
        void default_wiring();
        //declare array alternatively use pointer if dynamic array size needed
        int ciphermapping[26];
};
#endif