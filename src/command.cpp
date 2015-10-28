#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>
#include "instruction.h"

Command::Command(char* exe, char** args) {
    executable = exe;
    args = args;
}

Command::~Command() {
    delete(executable);
    delete(args);
}

bool Command::execute() {
    pid_t c_pid, pid;
    int status;

    cout << "executing command: " << executable << " with arguments: " << args;
    cout << endl;

    c_pid = fork();

    if (c_pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (c_pid == 0) {
        pid = getpid();

        execvp(executable, args);
        perror("Error executing");// + executable);
        exit(12);
    } else if (c_pid > 0) {
        if((pid = wait(&status)) < 0) {
            perror("wait");
            exit(1);
        }
    }
    return true;
}
