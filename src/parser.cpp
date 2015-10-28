
#include "parser.h"

const char * const Parser::CONNECTOR[] = { "&&", "||", ";" };

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

char** Parser::createArgArr(vector<char*>::const_iterator i) {
    char ** args = new char*[MAXARGS];

    cout << "Crating args[]" << endl;
    int j = 0;
    while (!isConnector(*i++)) {
        // add element to args[]
        args[j] = new char[sizeof(*i)];
        strcpy(args[j++], *i);
        cout << "args[" << j <<"] = " << args[j] << endl;
    }
    // args[j] = "\0";
    return args;
}

bool Parser::isConnector(char *token) {
    for (int i = 0; i < NUMCONNECTORS; i++) {
        if (!strcmp(token, CONNECTOR[i]))
            return true;
    }
    return false;
}

Instruction * Parser::createTree() {
    Instruction *exeTree = NULL;
    char * temp;

    vector<char*>::const_iterator i = tokLine.begin();
    cout << "Creating command: " << *i << endl;
    Command * cmd_1 = new Command(*(i++), createArgArr(i));
    cout << *i << endl;
    exeTree = cmd_1;
    cout << "First command created successfully!" << endl;
    while (i != tokLine.end()) {
        //Command * cmd_1 = new Command(*(i++), createArgArr(i));
        if (isConnector(*i)) {
            temp = *(i++);
            cout << "Creating command: " << *i << endl;
            Command * cmd_2 = new Command(*(i++), createArgArr(i));
            // deal with individual connectors
            Connector * conn = newConnector(cmd_1, cmd_2, i);
            exeTree = conn;
        }
    }
    return exeTree;
}

Connector * Parser::newConnector(Command * cmd_1, Command * cmd_2,
        vector<char*>::const_iterator i) {
    Connector *temp = NULL;
    if (!strcmp(*i, "&&")) {
        And *tempAnd =  new And(cmd_1, cmd_2);
        temp = tempAnd;
    } else if (strcmp(*i, "||")) {
        Or *tempOr =  new Or(cmd_1, cmd_2);
        temp = tempOr;
    } else if (strcmp(*i, ";")) {
        SemiColon *tempSemi =  new SemiColon(cmd_1, cmd_2);
        temp = tempSemi;
    }
    // error
    return temp;
}

void Parser::printall() {
    for (vector<char*>::const_iterator i = tokLine.begin();
            i != tokLine.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}
