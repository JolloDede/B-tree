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
void Node::insert(int value)
{
    Node *node = find(value);

    if (node == NULL)
    {
        std::cout << "Error didnt find Node";
    }
    

    int i = node->nV - 1;
    while (i >= 0 && node->values[i] > value)
    {
        i--;
    }
    if (node->values[i] == value)
    {
        std::cout << "Error cant insert";
        return;
    }

    if (node->nV == deg - 1)
    {
        i = node->nV - 1;
        while (i >= 0 && node->values[i] > value)
        {
            node->values[i + 1] = node->values[i];
            i--;
        }
        node->values[i+1] = value;

        if (node->parent != NULL)
        {
            node->parent->splitChild(node, 1, 1);
        }
        else
        {
            // New Rootnode
            Node *newRootnode = new Node(deg, false);
            newRootnode->parent = NULL;
            newRootnode->nV = 0;

            node->parent = newRootnode;
            newRootnode->children[0] = node;
            newRootnode->splitChild(node, 1, 0);
        }
    }
    else
    {
        i = node->nV - 1;
        while (i >= 0 && node->values[i] > value)
        {
            node->values[i + 1] = node->values[i];
            i--;
        }
        node->values[i + 1] = value;
        node->nV++;
    }
}

// Splits the child of de current node and decides where the value goes
void Node::splitChild(Node *smallNode, int median, int cSplit)
{
    Node *bigNode = new Node(deg, smallNode->leaf);
    bigNode->parent = this;

    for (int i = nV; i >= cSplit+1; i--)
    {
        children[i+1] = children[i];
    }
    children[cSplit+1] = bigNode;

    for (int i = median + 1; i < deg; i++)
    {
        bigNode->values[bigNode->nV] = smallNode->values[i];
        bigNode->nV++;
        smallNode->nV--;
    }

    int i = nV - 1;
    while (i >= 0 && values[i] > smallNode->values[median])
    {
        values[i + 1] = values[i];
        i--;
    }
    values[i + 1] = smallNode->values[median];
    if (nV == deg - 1)
    {
        if (parent == NULL)
        {
            //New Rootnode
            Node *newRootnode = new Node(deg, false);
            newRootnode->parent = NULL;
            newRootnode->nV = 0;

            parent = newRootnode;
            newRootnode->children[0] = this;
            newRootnode->splitChild(this, 1, 0);
            return;
        }
        else
        {
            parent->splitChild(this, 1, 1);
        }
    }
    nV++;
}

// The Nodes print itself with recursion starting at the rootNode
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

Node *Node::find(int value)
{
    int i = nV - 1;
    while (i >= 0 && values[i] > value)
    {
        i--;
    }

    if (values[i+1] == value)
    {
        return this;
    }
    if (!leaf)
    {
        return children[i + 1]->find(value);
    }
    if (leaf)
    {
        return this;
    }
    return NULL;
}
