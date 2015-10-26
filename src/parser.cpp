
#include "parser.h"

Parser::Parser(char * rawInput) {
    cout << "Creating Parser" << endl;
    tokLine = tokenize(rawInput);
}

Parser::~Parser() {
}

vector<char*> Parser::tokenize(char * line) {
    vector<char*> tokens;
    char * temp;
    char * token;

    cout << "Tokenizing." << endl;
    token = strtok(line, " ");
    while (token != NULL) {
        temp = new char[sizeof(token)];
        strcpy(temp,token);
        tokens.push_back(temp);
        token = strtok(NULL, " ");
    }

    return tokens;
}

//Instruction * Parser::createTree() {
//}

void Parser::printall() {
    for (vector<char*>::const_iterator i = tokLine.begin(); i != tokLine.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}
