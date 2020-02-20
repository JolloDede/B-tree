#include "node.h"

// Constructor Init size of children and values
Node::Node(int deg, bool leaf)
{
    Node::leaf = leaf;
    Node::deg = deg;

    values = new int[deg - 1];
    children = new Node *[deg];

    nV = 0;
    std::cout << "New Node" << std::endl;
}

// Inserting in a node wich is not Full
void Node::insertNonFull(int value)
{
    if (leaf)
    {
        int i = nV - 1;

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
        int i = nV;

        while (i > 0 && values[i - 1] > value)
        {
            i--;
        }

        if (children[i]->nV == deg - 1)
        {
            splitChild(1, children[i], value);

            return;
        }
        children[i]->insertNonFull(value);
    }
}

// Splits the child of de current node and decides where the value goes
void Node::splitChild(int i, Node *smallNode, int value)
{
    Node *bigNode = new Node(deg, smallNode->leaf);

    bigNode->nV = 1;

    smallNode->nV = 1;

    if (smallNode->values[0] < value)
    {
        if (smallNode->values[1] < value)
        {
            if (smallNode->values[1] > values[0] && nV != 0)
            {
                values[1] = smallNode->values[1];
            }
            else
            {
                values[1] = values[0];
                values[0] = smallNode->values[1];
            }
            bigNode->values[0] = value;
        }
        else
        {
            if (value > values[0] && nV != 0)
            {
                values[1] = value;
            }
            else
            {
                values[1] = values[0];
                values[0] = value;
            }
            bigNode->values[0] = smallNode->values[1];
        }
    }
    else
    {
        if (smallNode->values[0] > values[0] && nV != 0)
        {
            values[1] = smallNode->values[0];
        }
        else
        {
            values[1] = values[0];
            values[0] = smallNode->values[0];
        }
        smallNode->values[0] = value;
        bigNode->values[0] = smallNode->values[1];
    }
    nV++;
    children[i + 1] = bigNode;
}

// The Nodes print itself with recursion starting at the rootNode
void Node::printInOrder()
{
}
