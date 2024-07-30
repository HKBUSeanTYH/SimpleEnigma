#ifndef STRING_UTIL_DEF
#define STRING_UTIL_DEF
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm> // for using transform 
#include <cctype> // for using toupper 
namespace StringUtil {
    std::vector<std::string> split(std::string, std::string);
    void split_into(std::vector<std::string>&, std::string, std::string);
    //convert a char to its int representation 0-25 and vice versa
    int char_to_int(char);
    char int_to_char(int);
    int alphabet_to_int(char);
    char int_to_alphabet(int);
}
#endif