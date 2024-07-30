#ifndef PLUGBOARD_DEF
#define PLUGBOARD_DEF
#include "CipherMap.h"

class Plugboard : public CipherMap{
    public:
        int map(int) override;
        void process_mappings(std::vector<std::string>);
        ~Plugboard() {}

        friend std::ostream& operator<<(std::ostream& o, Plugboard const& a) {
            for (int idx = 0; idx < a.cipher_mapping.size(); ++idx) {
                int map_val = a.cipher_mapping[idx];
                if (map_val != idx) {
                    char cIdx = StringUtil::int_to_char(idx);
                    char cVal = StringUtil::int_to_char(map_val);
                    
                    o << cIdx << " is mapped to " << cVal << "\n";
                }
            }
            return o;
        }
};
#endif