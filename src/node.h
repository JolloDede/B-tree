#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h> 

struct Node
{
    // int *values;
    std::vector<int> values;
    int nV;
    Node *parent;
    std::vector<Node*> children;
    bool leaf;
    int deg;

    Node(int deg, bool leaf);
    void insert(int value);
    Node* find(int value);
    void deleteValue(int value);
    void merge(Node* node);
    void deleteFromLeaf(Node* node, bool bigger);
    int getChildIndex(Node* node);
    Node* getRightMostNode();
    void splitChild(Node *node, int median);
    void addValToNode(int val);
    void overFillNode(int value);
    void createNewRoot();
    
    void printInOrder();
};