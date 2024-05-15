#include <iostream>


#include "linenoise.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Program name not specified";
        return 1;
    }

    auto prog = argv[1];

    auto pid = fork();

    if (pid == 0) {
        // Child process => Execute debugee
        ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
        execl(prog, prog, nullptr);

    }
    else if (pid >= 1) {
        // Parent process => Execute debugger
    }
}