#ifndef PARSER_H
#define PARSER_H

#include "instruction.h"
#include "connectors.h"
#include <vector>
#include <string.h>

#define NUMCONNECTORS 3
#define MAXARGS 8
#define NUMCOMMENTS 1

using namespace std;

class Parser {
    private:
        vector<char*> tokLine;
        static const char * const CONNECTOR[];
        static const char * const COMMENT[];

        vector<char*> tokenize(char *);
        bool isConnector(char *);
        bool isComment(char *);
        char** createArgArr(vector<char*>::const_iterator &);
        Connector * newConnector(Instruction *, Instruction *, char*);

    public:
        Parser() {};
        Parser(char *);
        ~Parser();
        void parse(char *);
        Instruction * createTree();
        void printall();
};

#endif
