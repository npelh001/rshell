/*
 * Author: Nicholas Pelham
 * Date  : 10/29/15
 *
 * Command: Wrapper to execute individual commands within the greater program 
 * structure.
 */

// TO DO:
// * Correctly detect if an execvp call failed due to incorrect syntax, 
//   missing file/command, or other input related reasons.
// * Create way to handle special commands like exit.

#include "instruction.h"

Command::Command(char** args, int &error) {
    argv = args;
    err = &error;
}

Command::~Command() {
    delete(argv);
}

/*
 * execute: forks the process to allow a command to run before continuing
 *          program execution.
 */
bool Command::execute() {
    pid_t c_pid, pid;
    int status;

    c_pid = fork();

    if (c_pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (c_pid == 0) {
        pid = getpid();

        *err = execvp(argv[0], argv);
        perror("Error executing");
        exit(12);
    } else if (c_pid > 0) {
        if((pid = wait(&status)) < 0) {
            perror("wait");
            exit(1);
        }
    }

    if (*err == -1) {
        return false;
    }
    return true;
}
