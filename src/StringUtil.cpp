#include "StringUtil.h"

std::vector<std::string> StringUtil::split (std::string input, std::string delimiter) {
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

void StringUtil::split_into (std::vector<std::string>& vector, std::string input, std::string delimiter) {
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