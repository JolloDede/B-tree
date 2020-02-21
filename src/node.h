#include <iostream>
#include <stdlib.h>

struct Node
{
    int *values;
    int nV;
    Node *parent;
    Node **children;
    bool leaf;

    int deg;

    Node(int deg, bool leaf);
    void insert(int value);
    Node* find(int value);
    void splitChild(Node *node, int median, int cSplit);
    void printInOrder();
};