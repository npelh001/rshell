#include "instruction.h"

Instruction::Instruction() {
    left = NULL;
    right = NULL;
}

Instruction::~Instruction() {
    delete(left);
    delete(right);
}

Instruction::Instruction(Instruction * lInst, Instruction * rInst) {
    left = lInst;
    right = rInst;
}

Instruction * Instruction::addAsRoot(Instruction * root, 
        Instruction * newInst) {
    newInst->left = root;
    root = newInst;
    return root;
}

Instruction * Instruction::addLeaf(Instruction * root, 
        Instruction * newInst) {
    if (root != NULL)
        root->right = newInst;
    else
        root = newInst;
    return root;
}
