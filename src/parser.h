#ifndef PARSER_H
#define PARSER_H

#include "instruction.h"
#include <vector>
#include <string.h>

using namespace std;

class Parser {
    private:
        vector<char*> tokLine;

    public:
        Parser(char *);
        ~Parser();
        vector<char*> tokenize(char *);
        Instruction * createTree();
        void printall();
};

#endif
