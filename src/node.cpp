#include "node.h"

Node::Node(int amountValues, int deg, bool leaf)
{
    Node::leaf = leaf;

    values = new int[amountValues];
    children = new Node *[deg];

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

    }
}

void Node::splitChild(int i, Node *node)
{
    Node *newNode = new Node(sizeof(values), sizeof(children), node->leaf);
    newNode->nV = sizeof(values) / 2 - 1 - 1;

    for (int j = 0; j < sizeof(values) / 2 - 1; j++)
    {
        newNode->values[j] = node->values[j + sizeof(values) / 2 - 1];
    }

    if (!node->leaf)
    {
        for (int j = 0; j < sizeof(values) / 2 - 1; j++)
        {
            newNode->children[j] = node->children[j + sizeof(values) / 2 - 1];
        }
    }

    node->nV = sizeof(values) / 2 - 1;

    for (int j = 0; j < i + 1; j++)
    {
        children[j + 1] = children[j];
    }

    children[i + 1] = newNode;

    for (int j = 0; j < i + 1; j++)
    {
        values[j + 1] = values[j];
    }

    values[i] = node->values[sizeof(values) / 2 - 1];

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
        std::cout << " " << values[i];
    }

    if (!leaf)
    {
        children[i]->printInOrder();
    }
}
