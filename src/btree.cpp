#include "btree.h"

// Constructor Init a enmpty tree
BTree::BTree(int _degree)
{
    degree = _degree; // How many Children a Node can have
    rootNode = NULL;  // rootNode gets set to NULL
}

// main function that insert a new Value in the tree
void BTree::newValue(int value)
{
    if (rootNode == NULL)
    {
        rootNode = new Node(degree, true);
        rootNode->values[0] = value;
        rootNode->nV = 1;
    }
    else
    {
        rootNode->insert(value);
    }
}

void BTree::search(int value){
    if (rootNode->values[0] > value)
    {
        if (!rootNode->leaf)
        {
            rootNode->children[0] https://medium.com/@msanchez157/all-about-b-trees-7330962c1098
        }
        
    }
    
    rootNode->values[0]
}

// Main function Where the tree gets printed to the commandline
void BTree::printTree()
{
    std::cout << std::endl << "Rootnode: " << std::endl;
    std::cout << rootNode->nV << std::endl;
    for (int i = 0; i < rootNode->nV; i++)
    {
        std::cout << rootNode->values[i] << " ";
    }
    std::cout << std::endl << "Child 1: ";
    std::cout << std::endl
              << rootNode->children[0]->nV << std::endl;
    for (int i = 0; i < rootNode->children[0]->nV; i++)
    {
        std::cout << rootNode->children[0]->values[i] << " ";
    }
    std::cout << std::endl << "Child 2: ";
    std::cout << std::endl
              << rootNode->children[1]->nV << std::endl;
    for (int i = 0; i < rootNode->children[1]->nV; i++)
    {
        std::cout << rootNode->children[1]->values[i] << " ";
    }
    std::cout << std::endl << "Child 3: ";
    std::cout << std::endl
              << rootNode->children[2]->nV << std::endl;
    for (int i = 0; i < rootNode->children[2]->nV; i++)
    {
        std::cout << rootNode->children[2]->values[i] << " ";
    }
}