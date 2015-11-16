#ifndef PARSER_H
#define PARSER_H

#include "instruction.h"
#include "connectors.h"
#include <vector>
#include <stack>
#include <string.h>

#define NUMCONNECTORS 3
#define MAXARGS 8
#define NUMCOMMENTS 1
#define NUMPARENTYPES 2

using namespace std;

class Parser {
    private:
        static const char * const CONNECTOR[NUMCONNECTORS];
        static const char * const COMMENT[NUMCOMMENTS];
        static const char * const OPENPAREN[NUMPARENTYPES];
        static const char * const CLOSEPAREN[NUMPARENTYPES];
        vector<char*> tokLine;
        int error;

        vector<char*> tokenize(char *);
        bool isConnector(char *);
        bool isComment(char *);
        bool isExit(char *);
        bool isClosingParen(char *);
        char** createArgArr(vector<char*>::const_iterator &);
        Connector * newConnector(vector<char*>::const_iterator &);
        Connector * newConnector(Instruction *, Instruction *, char*);

    public:
        Parser() {};
        Parser(char *);
        ~Parser();
        void parse(char *);
        bool validParens(); // NEW METHOD
        Instruction * createTree();
        Instruction * addInstruction(Instruction *, 
                vector<char*>::const_iterator &); // NEW METHOD
};

#endif
