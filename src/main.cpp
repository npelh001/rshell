#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>
#include "parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    char *name, host[32];
    char line[1024];
    
    name = getlogin();
    gethostname(host, 32);

    while (1) {
        cout << name << "@" << host << " $ ";
        cin.getline(line,1024);

        if (!strcmp(line,"exit"))
            break;

        Parser parsed = Parser(line);
        
        Instruction * instruction = parsed.createTree();
        instruction->execute();
    }
}
