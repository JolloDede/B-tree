#include <iostream>
#include <vector>
#include "node.h"

class BTree
{
    Node *rootNode;

public:
    BTree(int _deg);

    void newValue(int value);
    bool deleteValue(int value);
    bool search(int value);
    void printTree();
    void printInOrder();
    void recTree(Node *node);
};