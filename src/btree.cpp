#include "btree.h"

// Constructor Init a enmpty tree
BTree::BTree(int _degree)
{
    rootNode = new Node(_degree, true);
    rootNode->nV = 0;
    rootNode->parent = NULL;
}

// main function that insert a new Value in the tree
void BTree::newValue(int value)
{
    rootNode->insert(value);
    if (rootNode->parent != NULL)
    {
        rootNode = rootNode->parent;
    }
}

bool BTree::search(int value)
{
    Node *node = rootNode->find(value);
    for (int i = 0; i < node->nV; i++)
    {
        if (node->values[i] == value)
        {
            return true;
        }
    }
    return false;
}

// Main function Where the tree gets printed to the commandline
void BTree::printTree()
{
    std::cout << sizeof(rootNode->children) << std::endl;
    std::cout << sizeof(*rootNode->children) << std::endl;
    std::cout << sizeof(Node*) << std::endl;
    std::cout << std::endl
              << "Rootnode: " << std::endl;
    std::cout << rootNode->nV << std::endl;
    for (int i = 0; i < rootNode->nV; i++)
    {
        std::cout << rootNode->values[i] << " ";
    }
    std::cout << std::endl
              << "Rootchild 1: ";
    std::cout << std::endl
              << rootNode->children[0]->nV << std::endl;
    for (int i = 0; i < rootNode->children[0]->nV; i++)
    {
        std::cout << rootNode->children[0]->values[i] << " ";
    }
    std::cout << std::endl
              << "Child 1 Child 1: ";
    std::cout << std::endl
              << rootNode->children[0]->children[0]->nV << std::endl;
    for (int i = 0; i < rootNode->children[0]->children[0]->nV; i++)
    {
        std::cout << rootNode->children[0]->children[0]->values[i] << " ";
    }
    std::cout << std::endl
              << "Child 1 Child 2: ";
    std::cout << std::endl
              << rootNode->children[0]->children[1]->nV << std::endl;
    for (int i = 0; i < rootNode->children[0]->children[1]->nV; i++)
    {
        std::cout << rootNode->children[0]->children[1]->values[i] << " ";
    }

    std::cout << std::endl
              << "Rootchild 2: ";
    std::cout << std::endl
              << rootNode->children[1]->nV << std::endl;
    for (int i = 0; i < rootNode->children[1]->nV; i++)
    {
        std::cout << rootNode->children[1]->values[i] << " ";
    }
    std::cout << std::endl
              << "Child 2 Child 1: ";
    std::cout << std::endl
              << rootNode->children[1]->children[0]->nV << std::endl;
    for (int i = 0; i < rootNode->children[1]->children[0]->nV; i++)
    {
        std::cout << rootNode->children[1]->children[0]->values[i] << " ";
    }
    // std::cout << std::endl
    //           << "Child 2 Child 2: ";
    // std::cout << std::endl
    //           << rootNode->children[1]->children[1]->nV << std::endl;
    // for (int i = 0; i < rootNode->children[1]->children[1]->nV; i++)
    // {
    //     std::cout << rootNode->children[1]->children[1]->values[i] << " ";
    // }
    // std::cout << std::endl
    //           << "Child 2 Child 3: ";
    // std::cout << std::endl
    //           << rootNode->children[1]->children[2]->nV << std::endl;
    // for (int i = 0; i < rootNode->children[1]->children[2]->nV; i++)
    // {
    //     std::cout << rootNode->children[1]->children[2]->values[i] << " ";
    // }

    std::cout << std::endl
              << "Rootchild 3: ";
    std::cout << std::endl
              << rootNode->children[2]->nV << std::endl;
    for (int i = 0; i < rootNode->children[2]->nV; i++)
    {
        std::cout << rootNode->children[2]->values[i] << " ";
    }
    std::cout << std::endl
              << "Rootchild 3 Child 1: ";
    std::cout << std::endl
              << rootNode->children[2]->children[0]->nV << std::endl;
    for (int i = 0; i < rootNode->children[2]->children[0]->nV; i++)
    {
        std::cout << rootNode->children[2]->children[0]->values[i] << " ";
    }
    std::cout << std::endl
              << "Rootchild 3 Child 2: ";
    std::cout << std::endl
              << rootNode->children[2]->children[1]->nV << std::endl;
    for (int i = 0; i < rootNode->children[2]->children[1]->nV; i++)
    {
        std::cout << rootNode->children[2]->children[1]->values[i] << " ";
    }
}

void BTree::printInOrder()
{
    std::cout << std::endl
              << std::endl;
    rootNode->printInOrder();
}
