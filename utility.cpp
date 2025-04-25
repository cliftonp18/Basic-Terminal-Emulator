// utility.cpp
#include "utility.h"
#include <sstream>

std::vector<char*> castArgs(const std::vector<std::string>& cmd) {
    std::vector<char*> result;
    for (const auto& s : cmd) {
        result.push_back(const_cast<char*>(s.c_str()));
    }
    result.push_back(nullptr);
    return result;
}

std::vector<std::string> cmd2vec(const std::string& command, char delimiter) {
    std::vector<std::string> result;
    std::istringstream iss(command);
    std::string token;
    while (std::getline(iss, token, delimiter)) {
        if (!token.empty()) result.push_back(token);
    }
    return result;
}
