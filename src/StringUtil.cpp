#include "StringUtil.h"

/*
    TODO: look into move semantics. avoid unnecessary copies (even if copy elision may occur).
*/
std::vector<std::string> StringUtil::split (const std::string& input, const std::string& delimiter) {
    std::vector<std::string> output;
    size_t start {0}, end {0}, delim_len {delimiter.size()};
    std::string token;
    while ((end = input.find(delimiter, start)) != std::string::npos) {
        token = input.substr(start, end-start);
        output.push_back(token);
        start = end + delim_len;
    }
    output.push_back(input.substr(start));
    return output;
}

void StringUtil::split_into (std::vector<std::string>& vector, const std::string& input, const std::string& delimiter) {
    vector.clear();
    size_t start {0}, end {0}, delim_len {delimiter.size()};
    std::string token;
    while ((end = input.find(delimiter, start)) != std::string::npos) {
        token = input.substr(start, end-start);
        vector.push_back(token);
        start = end + delim_len;
    }
    vector.push_back(input.substr(start));
}

char StringUtil::int_to_char(int i) {
    return static_cast<char>(i + 65);
}

int StringUtil::char_to_int(char c) {
    return static_cast<int>(c) - 65;
}

int StringUtil::alphabet_to_int(char c) {
    if (c < 'A' || c > 'Z') {
        throw std::invalid_argument("Invalid char: " + std::to_string(c) + ". Only accepts alphabets");
    }
    return char_to_int(c);
}

char StringUtil::int_to_alphabet(int i) {
    if (i < 0 || i > 25) {
        throw std::invalid_argument("Invalid int: " + std::to_string(i) + ". Accepts 0 - 25");
    }
    return int_to_char(i);
}