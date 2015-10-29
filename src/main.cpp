#include <iostream>
#include "parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    char *name, host[32];
    char line[1024];
    Parser parser;
    Instruction *instruction;
    
    // Get info for input prompt
    name = getlogin();
    gethostname(host, 32);

    while (1) {
        cout << name << "@" << host << " $ ";
        cin.getline(line,1024);

        // Exit command
        if (!strcmp(line,"exit"))
            break;

        parser.parse(line);
        
        instruction = parser.createTree();
        instruction->execute();

        delete instruction;
    }
}
