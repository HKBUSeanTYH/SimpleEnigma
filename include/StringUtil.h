#ifndef STRING_UTIL_DEF
#define STRING_UTIL_DEF
#include <vector>
#include <string>
#include <algorithm> // for using transform 
#include <cctype> // for using toupper 

std::vector<std::string> split(std::string, std::string);
void split_into(std::vector<std::string>&, std::string, std::string);
#endif