#ifndef CONNECTORS_H
#define CONNECTORS_H

#include "instruction.h"

class And : public Connector {
    private:
    public:
        And() : Connector() {};
        And(Instruction *, Instruction *);
        virtual ~And();
        virtual bool execute();
};

class Or : public Connector {
    private:
    public:
        Or() : Connector() {};
        Or(Instruction *, Instruction *);
        virtual ~Or();
        virtual bool execute();
};

class SemiColon : public Connector {
    private:
    public:
        SemiColon() : Connector() {};
        SemiColon(Instruction *, Instruction *);
        virtual ~SemiColon();
        virtual bool execute();
};

#endif
