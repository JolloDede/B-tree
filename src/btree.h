#include <iostream>
#include <vector>
#include "node.h"

class BTree
{
    Node *rootNode;
    int degree;

public:
    BTree(int _deg);

    void newValue(int value);
    void search(int value);
    void printTree();
    void recTree(Node *node);
};