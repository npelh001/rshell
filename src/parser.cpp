/*
 * Author: Nicholas Pelham
 * Date  : 10/29/15
 *
 * Parser: Deals with all raw input.
 *         Tokenizes an input line.
 *         Creates argv[] array for commands.
 *         Deals with all aspects of creating the tree used for execution
 *         of all input commands.
 */

#include "parser.h"

const char * const Parser::CONNECTOR[] = { "&&", "||", ";" };
const char * const Parser::COMMENT[] = { "#" };

Parser::Parser(char * rawInput) {
    parse(rawInput);
    error = 0;
}

Parser::~Parser() {
}

/*
 * parse: stores rawInput as a tokenized vector of c style strings.
 */
void Parser::parse(char * rawInput) {
    tokLine = tokenize(rawInput);
}
/*
 * tokenize: breaks up raw input into a tokenized array of c style strings.
 *           returns a vector of all the tokens created.
 */
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

/*
 * createArgArr: creates an array of c style strings to be used in command 
 *               execution.
 *               Used to create instances of Command
 */
char** Parser::createArgArr(vector<char*>::const_iterator &i) {
    char ** args = new char*[MAXARGS];

    int j = 0;
    while ((i != tokLine.end()) && !isConnector(*i) && !isComment(*i)) {
        // add element to args[]
        args[j] = new char[sizeof(*i)];
        strcpy(args[j++], (const char*)*i++);
    }
    args[j] = NULL;
    return args;
}

/*
 */
bool Parser::isConnector(char *token) {
    for (int i = 0; i < NUMCONNECTORS; i++) {
        if (strcmp(token, CONNECTOR[i]) == 0)
            return true;
    }
    return false;
}

/*
 */
bool Parser::isComment(char *token) {
    for (int i = 0; i < NUMCOMMENTS; i++) {
        if (strcmp(token, COMMENT[i]) == 0)
            return true;
    }
    return false;
}

/* 
 * createTree: Creates a command tree out of information stored in tokLine.
 *             The tree is stored as instances of Instruction, but each node
 *             is either a Command or a Connector.
 *             All leaves should be Commans.
 */
Instruction * Parser::createTree() {
    Instruction *exeTree = NULL;
    char * temp;
    Command *cmd_1, *cmd_2;
    Connector *conn;

    vector<char*>::const_iterator i = tokLine.begin();
    if (!isComment(*i)) {
        cmd_1 = new Command(createArgArr(i), error);
        exeTree = cmd_1;
    }
    while (i != tokLine.end() && isConnector(*i) && !isComment(*i)) {
        temp = *i++;
        cmd_2 = new Command(createArgArr(i), error);
        // deal with individual connectors
        conn = newConnector(exeTree, cmd_2, temp);
        exeTree = conn;
    }
    return exeTree;
}

/*
 * newConnector: Creates a new connector from a pair of Instructionsand a 
 * C style string containing the characters representing that connection
 */
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
