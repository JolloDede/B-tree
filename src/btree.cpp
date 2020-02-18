#include "btree.h"

BTree::BTree(int _amountValues, int _degree)
{
    amountOfValues = _amountValues;
    degree = _degree;
    rootNode = NULL;
}

// void BTree::xorSwap(int *x, int *y)
// {
//     if (x != y)
//     { //ensure that memory locations are different
//         *x ^= *y;
//         *y ^= *x;
//         *x ^= *y;
//     }
// }

void BTree::child(Node *node, int value)
{
    if (node->leaf)
    {
        if (node->nV == amountOfValues)
        {

        }
    }
}

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
        if (rootNode->nV == 2*rootNode->deg-1)
        {
            Node *newRootNode = new Node(rootNode->deg, false);

            newRootNode->children[0] = rootNode;

            newRootNode->splitChild(0, rootNode);

            int i = 0;
            if (newRootNode->values[0] < value)
            {
                i++;
            }
            newRootNode->children[i]->insertNonFull(value);

            rootNode = newRootNode;
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

    std::cout << rootNode->values[0] << " ";
    std::cout << rootNode->values[1] << std::endl;

    std::cout << rootNode->children[0]->values[0] << " ";
    std::cout << rootNode->children[0]->values[1] << std::endl;

    std::cout << rootNode->children[1]->values[0] << " ";
    std::cout << rootNode->children[1]->values[1] << std::endl;

    std::cout << rootNode->children[2]->values[0] << " ";
    std::cout << rootNode->children[2]->values[1] << std::endl;

    // recTree(rootNode);

    // if (rootNode->children[1] != NULL)
    // {
    //     std::cout << sizeof(*rootNode->children[0]->values[1]);
    //     std::cout << sizeof(rootNode->children[1]->values[1]);
    // }
}

void BTree::recTree(Node *node)
{
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