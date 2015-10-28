#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>
#include "parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    char line[1024];
    pid_t c_pid, pid;
    int status;

    while (1) {
        cout << "$ ";
        cin.getline(line,1024);
        if (!strcmp(line,"exit"))
            break;

        c_pid = fork();

        if (pid < 0) {
            cout << "pid = 0" << endl;
            perror("fork failed");
            exit(1);
        } else if (c_pid == 0) {
            pid = getpid();

        //    cout << "Running parser on line." << endl;
            Parser parsed = Parser(line);
         //   cout << "printing parser information." << endl;
         //   parsed.printall();
            
            Instruction * instruction = parsed.createTree();
            instruction->execute();
            exit(12);
        } else if (c_pid > 0) {
            if ((pid = wait(&status)) < 0) {
                perror("wait");
                exit(1);
            }
        }
    }
}
