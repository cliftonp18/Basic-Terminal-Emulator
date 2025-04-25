#pragma once
#include <string>
#include <vector>

std::vector<char*> castArgs(const std::vector<std::string>& cmd);
std::vector<std::string> cmd2vec(const std::string& command, char delimiter = ' ');
