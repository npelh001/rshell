#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class Instruction {
    private:
    protected:
        Instruction * left;
        Instruction * right;

    public:
        Instruction();
        Instruction(Instruction * lInst, Instruction * rInst);
        virtual ~Instruction();
        virtual bool execute() = 0;
        Instruction * addAsRoot(Instruction *, Instruction *);
        Instruction * addLeaf(Instruction *, Instruction *);
};

class Command : public Instruction {
    private:
        char ** argv;
        int * err;

    public:
        Command();
        Command(char **, int &);
        ~Command();
        virtual bool execute();
};

class Connector : public Instruction {
    private:

    public:
        Connector() : Instruction() {};
        Connector(Instruction * lInst, Instruction * rInst);
        virtual ~Connector();
        virtual bool execute() = 0;
};

#endif
