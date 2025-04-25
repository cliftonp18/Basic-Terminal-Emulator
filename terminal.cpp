// terminal.cpp
#include "terminal.h"
#include "mypipe.h"
#include "utility.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int run_cmd(std::vector<char*> argv) {
    mypipe pipe;
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        pipe.redirect();
        execvp(argv[0], argv.data());
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else {
        int status;
        waitpid(pid, &status, 0);
        std::string output = pipe.read();
        std::cout << output;
        return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
    }
}

void terminal_app() {
    std::string input;
    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, input);
        if (input == "exit") break;
        auto args = cmd2vec(input);
        if (!args.empty()) {
            auto argv = castArgs(args);
            run_cmd(argv);
        }
    }
}
