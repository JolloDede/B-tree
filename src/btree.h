#include <iostream>
#include <vector>
#include "node.h"

class btree
{
    int valueAmount;
    node *rootNode;
    int degree;

public:
    btree(int _numberOfChildren, int _deg);

    void xorSwap(int *x, int *y);
    void newValue(int value);
    void insert(int value);
    void printTree();

private:
    std::vector<node> nodeList;
};