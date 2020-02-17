#include "btree.h"

BTree::BTree(int _amountValues, int _degree)
{
    amountOfValues = _amountValues;
    degree = _degree;
    rootNode = NULL;
}

void BTree::xorSwap(int *x, int *y)
{
    if (x != y)
    { //ensure that memory locations are different
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

void BTree::newValue(int value)
{
    if (rootNode == NULL)
    {
        rootNode = new Node(amountOfValues,degree,true);
        rootNode->values[0] = value;
        rootNode->nV = 1;
    }
    else
    {
        if (rootNode->nV == amountOfValues)
        {
            Node *newNode = new Node(amountOfValues, degree, false);

            newNode->children[0] = rootNode;

            newNode->splitChild(0, rootNode);

            int i = 0;
            if(newNode->values[0] < value){
                i++;
            }
            newNode->children[i]->insertNonFull(value);

            rootNode = newNode;
        }
        else
        {
            rootNode->insertNonFull(value);
        }
    }
}

void BTree::printTree()
{
    rootNode->printInOrder();

    // recTree(rootNode);

    // if (rootNode->children[1] != NULL)
    // {
    //     std::cout << sizeof(rootNode->children[0]->values[1]);
    //     std::cout << sizeof(rootNode->children[1]->values[1]);
    // }
}

void BTree::recTree(Node *node){
    if (node->children[0] != NULL)
    {
        recTree(node->children[0]);
    }

    std::cout << "node { ";
    for (int i = 0; i < node->nV; i++)
    {
        std::cout << "[" << node->values[i] << "] ";
    }
    std::cout << "}" << std::endl;
    return;
}