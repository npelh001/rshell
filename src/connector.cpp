#include "instruction.h"
#include "connectors.h"

Connector::Connector(Instruction *lInst, Instruction * rInst) {
    left = lInst;
    right = rInst;
}

Connector::~Connector() {
    delete(left);
    delete(right);
}

void Connector::print() {
    left->print();
    right->print();
}

And::And(Instruction *lInst, Instruction *rInst) 
        : Connector(lInst, rInst) {
}

And::~And() {
}

bool And::connect() {
    if (left->execute())
        return right->execute();
    return false;
}

Or::Or(Instruction * lInst, Instruction * rInst) 
    : Connector(lInst, rInst) {
}

Or::~Or() {
}

bool Or::connect() {
    if (left->execute())
        return true;
    if (right->execute())
        return true;
    return false;
}

SemiColon::SemiColon(Instruction * lInst, Instruction * rInst)
    : Connector(lInst, rInst) {
}

SemiColon::~SemiColon() {
}

bool SemiColon::connect() {
    left->execute();
    right->execute();
    return true;
}
