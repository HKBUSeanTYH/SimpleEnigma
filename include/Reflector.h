#ifndef REFLECTOR_DEF
#define REFLECTOR_DEF
#include <fstream>
#include "CipherMap.h"

class Reflector : public CipherMap {
    public:
        int map(int) override;
        Reflector(std::vector<std::string> mappings) : CipherMap{mappings} { }
        static Reflector create_reflector(std::string path);

        friend std::ostream& operator<<(std::ostream& o, Reflector const& a) {
            for (int i = 0; i < a.cipher_mapping.size(); ++i) {
                o << int_to_char(i) << " ";
            }
            o << "\n";
            for (int i = 0; i < a.cipher_mapping.size(); ++i) {
                o << int_to_char(a.cipher_mapping[i]) << " ";
            }
            o << "\n";
            return o;
        }
};
#endif