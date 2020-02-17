#include <iostream>
#include <stdlib.h>

struct Node
{
    int *values;
    int nV;
    Node *parent;
    Node **children;
    bool leaf;

    Node(int amountValues, int deg, bool leaf);
    void insertNonFull(int value);
    void splitChild(int i, Node *node);
    void printInOrder();
};