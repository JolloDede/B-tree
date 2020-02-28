#include <iostream>
#include <vector>
#include <stdlib.h>

struct Node
{
    int *values;
    int nV;
    Node *parent;
    std::vector<Node*> children;
    bool leaf;

    int deg;

    Node(int deg, bool leaf);
    void insert(int value);
    Node* find(int value);
    void splitChild(Node *node, int median);
    void addValToNode(int val);
    void printInOrder();
};