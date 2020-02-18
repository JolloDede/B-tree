#include "node.h"

Node::Node(int deg, bool leaf)
{
    Node::leaf = leaf;
    Node::deg = deg;

    values = new int[2*deg-1];
    children = new Node *[2*deg];

    nV = 0;
    std::cout << "New Node" << std::endl;
}

void Node::insertNonFull(int value)
{
    int i = nV - 1;
    if (leaf)
    {
        while (i >= 0 && values[i] > value)
        {
            values[i + 1] = values[i];
            i--;
        }
        values[i + 1] = value;
        nV++;
    }
    else
    {
        while (i >= 0 && values[i] > value)
        {
            i--;
        }

        if (children[i + 1]->nV == 2 * deg - 1)
        {
            // std::cout << sizeof(children) / sizeof(*children);
            splitChild(i + 1, children[i + 1]);

            if (values[i + 1] < value)
            {
                i++;
            }
        }
        children[i + 1]->insertNonFull(value);
    }
}

void Node::splitChild(int i, Node *nodeLeft)
{
    Node *nodeRight = new Node(deg, nodeLeft->leaf);
    nodeRight->nV = deg - 1;

    for (int j = 0; j < deg - 1; j++)
    {
        nodeRight->values[j] = nodeLeft->values[j + deg];
    }

    if (!nodeLeft->leaf)
    {
        for (int j = 0; j < deg; j++)
        {
            nodeRight->children[j] = nodeLeft->children[j + deg];
        }
    }

    nodeLeft->nV = deg - 1;

    for (int j = nV; j >= i + 1; j--)
    {
        children[j + 1] = children[j];
    }

    children[i + 1] = nodeRight;

    for (int j = nV - 1; j >= i; j--)
    {
        values[j + 1] = values[j];
    }

    values[i] = nodeLeft->values[deg - 1];

    nV++;
}

void Node::printInOrder()
{
    int i;
    for (i = 0; i < nV; i++)
    {
        if (!leaf)
        {
            children[i]->printInOrder();
        }
        std::cout << "nV: " << nV;
        std::cout << " " << values[i] << std::endl;
    }

    if (!leaf)
    {
        children[i]->printInOrder();
    }
}
