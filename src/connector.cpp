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

And::And(Instruction *lInst, Instruction *rInst) 
        : Connector(lInst, rInst) {
}

And::~And() {
}

bool And::connect() {
    left->execute();
    // if it succeeds
    right->execute();
    // if it succeeds
    // return true;
    return false;
}

Or::Or(Instruction * lInst, Instruction * rInst) 
    : Connector(lInst, rInst) {
}

Or::~Or() {
}

bool Or::connect() {
    left->execute();
    // if it succeeds
    // return true;
    // else
    right->execute();
    // if it succeeds
    // return true
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
