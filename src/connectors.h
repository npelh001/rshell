#ifndef CONNECTORS_H
#define CONNECTORS_H

#include "instruction.h"

class And : public Connector {
    private:
    public:
        And(Instruction *, Instruction *);
        virtual ~And();
        virtual bool connect();
};

class Or : public Connector {
    private:
    public:
        Or(Instruction *, Instruction *);
        virtual ~Or();
        virtual bool connect();
};

class SemiColon : public Connector {
    private:
    public:
        SemiColon(Instruction *, Instruction *);
        virtual ~SemiColon();
        virtual bool connect();
};

#endif
