#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
//#include <string.h>
#include <iostream>
#include "instruction.h"

Command::Command(char* exe, char** args) {
    executable = exe;
    argv = args;
    cout << executable << " command created." << endl;
}

Command::~Command() {
    delete(executable);
    delete(argv);
}

bool Command::execute() {
//    pid_t c_pid, pid;
//    int status;

//    cout << "executing command: " << executable << " with arguments: " << args;
//    cout << endl;
//
//    c_pid = fork();

//    if (c_pid < 0) {
//        perror("fork failed");
//        exit(1);
//    } else if (c_pid == 0) {
//        pid = getpid();

        execvp(executable, argv);
        perror("Error executing");// + executable);
//        exit(12);
//    } else if (c_pid > 0) {
//        if((pid = wait(&status)) < 0) {
//            perror("wait");
//            exit(1);
//        }
//    }
    return true;
}

void Command::print() {
    cout << "Executable: " << executable << endl;
    /*int i = 0;
    while (strcmp(args[i], (char*)"\0")) {
        cout << "args[" << i << "] = " << args[i++] << endl;
    }*/
    cout << argv[0] << endl;
}
