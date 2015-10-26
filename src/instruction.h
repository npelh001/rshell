#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Instruction {
    private:

    public:
        Instruction() {};
        virtual ~Instruction() {};
        virtual bool execute() = 0;
};

class Command : public Instruction {
    private:
        char * executable;
        char ** args;

    public:
        Command();
        ~Command();
        bool execute();
};

class Connector : public Instruction {
    private:
        Instruction * left;
        Instruction * right;

    public:
        Connector(Instruction * lInst, Instruction * rInst);
        virtual ~Connector();
        virtual bool execute() = 0;
};

#endif
