
#include "parser.h"

const char * const Parser::CONNECTOR[] = { "&&", "||", ";" };
const char * const Parser::COMMENT[] = { "#" };

Parser::Parser(char * rawInput) {
    tokLine = tokenize(rawInput);
}

Parser::~Parser() {
}

vector<char*> Parser::tokenize(char * line) {
    vector<char*> tokens;
    char * temp;
    char * token;

    token = strtok(line, " ");
    while (token != NULL) {
        temp = new char[sizeof(token)];
        strcpy(temp,token);
        tokens.push_back(temp);
        token = strtok(NULL, " ");
    }

    return tokens;
}

char** Parser::createArgArr(vector<char*>::const_iterator &i) {
    char ** args = new char*[MAXARGS];

    int j = 0;
    while ((i != tokLine.end()) && !isConnector(*i)
            && !isComment(*i)) {
        // add element to args[]
        args[j] = new char[sizeof(*i)];
        strcpy(args[j++], (const char*)*i++);
    }
    args[j] = NULL;
    return args;
}

bool Parser::isConnector(char *token) {
    for (int i = 0; i < NUMCONNECTORS; i++) {
        if (strcmp(token, CONNECTOR[i]) == 0)
            return true;
    }
    return false;
}

bool Parser::isComment(char *token) {
    for (int i = 0; i < NUMCOMMENTS; i++) {
        if (strcmp(token, COMMENT[i]) == 0)
            return true;
    }
    return false;
}

Instruction * Parser::createTree() {
    Instruction *exeTree = NULL;
    char * temp;
    Command *cmd_1, *cmd_2;
    Connector *conn;

    vector<char*>::const_iterator i = tokLine.begin();
    cmd_1 = new Command(*i, createArgArr(i));
    exeTree = cmd_1;
    while (i != tokLine.end() && isConnector(*i)
            && !isComment(*i)) {
        temp = *i++;
        cmd_2 = new Command(*i, createArgArr(i));
        // deal with individual connectors
        conn = newConnector(exeTree, cmd_2, temp);
        exeTree = conn;
    }
    return exeTree;
}

Connector * Parser::newConnector(Instruction * inst_1, Instruction * inst_2,
        char* conn) {
    Connector *temp = NULL;
    if (strcmp(conn, "&&") == 0) {
        And *tempAnd =  new And(inst_1, inst_2);
        temp = tempAnd;
    } else if (strcmp(conn, "||") == 0) {
        Or *tempOr =  new Or(inst_1, inst_2);
        temp = tempOr;
    } else { // if (!strcmp(conn, ";")) {
        SemiColon *tempSemi =  new SemiColon(inst_1, inst_2);
        temp = tempSemi;
    }
    return temp;
}

void Parser::printall() {
    for (vector<char*>::const_iterator i = tokLine.begin();
            i != tokLine.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}
