#ifndef PARSER_H
#define PARSER_H

#include "instruction.h"
#include "connectors.h"
#include <vector>
#include <string.h>

#define NUMCONNECTORS 3
#define MAXARGS 8

using namespace std;

class Parser {
    private:
        vector<char*> tokLine;
        static const char * const CONNECTOR[];

    public:
        Parser(char *);
        ~Parser();
        vector<char*> tokenize(char *);
        char** createArgArr(vector<char*>::const_iterator);
        bool isConnector(char *);
        Instruction * createTree();
        Connector * newConnector(Command *, Command *, 
                vector<char*>::const_iterator);
        void printall();
};

#endif
