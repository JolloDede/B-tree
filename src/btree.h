#include <iostream>
#include <vector>
#include "node.h"

class BTree
{
    int amountOfValues;
    Node *rootNode;
    int degree;

public:
    BTree(int _numberOfChildren, int _deg);

    void xorSwap(int *x, int *y);
    void newValue(int value);
    void printTree();
    void recTree(Node *node);
};