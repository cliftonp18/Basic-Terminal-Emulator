// mypipe.cpp
#include "mypipe.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>
#include <cstring>

mypipe::mypipe() {
    if (pipe(fd.data()) == -1) {
        throw std::runtime_error("Failed to create pipe");
    }
}

mypipe::~mypipe() {
    close(fd[0]);
    close(fd[1]);
}

void mypipe::redirect() {
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
}

std::string mypipe::read() {
    close(fd[1]);
    char buffer[4096];
    std::string output;
    ssize_t count;
    while ((count = ::read(fd[0], buffer, sizeof(buffer))) > 0) {
        output.append(buffer, count);
    }
    return output;
}

