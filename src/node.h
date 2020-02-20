#include <iostream>
#include <stdlib.h>

struct Node
{
    int *values;
    int nV;
    // Node *parent;
    Node **children;
    bool leaf;

    int deg;

    Node(int deg, bool leaf);
    void insertNonFull(int value);
    void splitChild(int i, Node *node, int value);
    void printInOrder();
};