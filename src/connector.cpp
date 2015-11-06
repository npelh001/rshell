/*
 * Author: Nicholas Pelham
 * Date  : 10/29/15
 *
 * All members relating to connectors are defined here.
 *
 * Connector: Used as a template for all connectors.
 * And      :
 * Or       :
 * SemiColon:
 */

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

/*
 * Execute the right Instruction only if the left succeeds.
 * Returns false if either Instruction fails.
 */
bool And::execute() {
    if (left->execute())
        return right->execute();
    return false;
}

Or::Or(Instruction * lInst, Instruction * rInst) 
    : Connector(lInst, rInst) {
}

Or::~Or() {
}

/*
 * Execute the right Instruction only if the left fails.
 * Returns true if either Instruction succeeds.
 */
bool Or::execute() {
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

/*
 * Executes both Instructions regardless of success or failure.
 */
bool SemiColon::execute() {
    left->execute();
    right->execute();
    return true;
}
