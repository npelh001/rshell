
#include "parser.h"

const char * const Parser::CONNECTOR[] = { "&&", "||", ";" };

Parser::Parser(char * rawInput) {
    //cout << "Creating Parser" << endl;
    tokLine = tokenize(rawInput);
}

Parser::~Parser() {
}

vector<char*> Parser::tokenize(char * line) {
    vector<char*> tokens;
    char * temp;
    char * token;

    //cout << "Tokenizing." << endl;
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
    /*int k = 0;
    vector<char*>::const_iterator h = i;
    while (!isConnector(*h) && h++ != tokLine.end()) {
        k++;
    }*/
    char ** args = new char*[MAXARGS];
    //cout << "Created args[]" << endl;

    //cout << "Crating args[]" << endl;
    int j = 0;
    while (((i != tokLine.end()) && !isConnector(*i))) {
        // add element to args[]
        args[j] = new char[sizeof(*i)];
        //cout << "*i = " << *i << endl;
        strcpy(args[j++], (const char*)*i++);
        cout << "args[" << (j-1) <<"] = " << args[j-1] << endl;
    }
    args[j] = NULL;
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
//    Instruction *exeTree = NULL;
//    char * temp;
//    Command *cmd_1, *cmd_2;
//    Connector *conn;

    vector<char*>::const_iterator i = tokLine.begin();
    //cout << "Creating command: " << *i << endl;
    Command * cmd_1 = new Command(*i, createArgArr(i));
    //cmd_1->print();
    //cout << *i << endl;
//    exeTree = cmd_1;
    //cout << "First command created successfully!" << endl;
//    while (i != tokLine.end()) {
//        cmd_1 = new Command(*i, createArgArr(i));
//        exeTree = cmd_1;
//        while (isConnector(*i)) {
//            temp = *i++;
//            //cout << "Creating command: " << *i << endl;
//            cmd_2 = new Command(*i, createArgArr(i));
//            // deal with individual connectors
//            conn = newConnector(exeTree, cmd_2, temp);
//            //cout << "Command created successfully!" << endl;
//            exeTree = conn;
//        }
//    }
//    return exeTree;
    return cmd_1;
}

Connector * Parser::newConnector(Instruction * inst_1, Instruction * inst_2,
        char* conn) {
    Connector *temp = NULL;
    if (strcmp(conn, "&&") == 0) {
        cout << "Creating AND connector." << endl;
        And *tempAnd =  new And(inst_1, inst_2);
        temp = tempAnd;
    } else if (strcmp(conn, "||") == 0) {
        cout << "Creating OR connector." << endl;
        Or *tempOr =  new Or(inst_1, inst_2);
        temp = tempOr;
    } else { // if (!strcmp(conn, ";")) {
        cout << "Creating SEMICOLOR connector." << endl;
        SemiColon *tempSemi =  new SemiColon(inst_1, inst_2);
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
