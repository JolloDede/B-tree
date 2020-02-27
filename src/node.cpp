#include "node.h"

// Constructor Init size of children and values
Node::Node(int deg, bool leaf)
{
    std::cout << "n1";
    Node::leaf = leaf;
    Node::deg = deg;
    std::cout << "n2";
    values = new int[deg - 1];
    parent = nullptr;
    nV = 0;
    std::cout << "New Node" << std::endl;
}

// Inserting in a node wich is not Full
void Node::insert(int value)
{
    if (leaf)
    {
        if (nV == deg - 1)
        {
            int i = nV - 1;
            while (i >= 0 && values[i] > value)
            {
                values[i + 1] = values[i];
                i--;
            }
            values[i + 1] = value;
            int med = sizeof(values) / sizeof(*values);
            std::cout << "a1";
            if (parent == nullptr)
            {
                std::cout << "ta1";
                Node *newRoot = new Node(deg, false);
                std::cout << "ta2";
                newRoot->children.push_back(this);

                parent = newRoot;
            }
            std::cout << "a2";
            parent->splitChild(this, med);
        }
        else
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
    }
    else
    {
        int i = nV - 1;
        while (i >= 0 && values[i] > value)
        {
            i--;
        }
        children[i + 1]->insert(value);
    }
}

// Splits the child of de current node and decides where the value goes
void Node::splitChild(Node *smallNode, int median)
{
    std::cout << "s1";
    if (nV == deg - 1)
    {
        std::cout << "ts1";
        int i = nV - 1;
        while (i >= 0 && values[i] > smallNode->values[median])
        {
            values[i + 1] = values[i];
            i--;
        }
        values[i + 1] = smallNode->values[median];
        int med = sizeof(values) / sizeof(*values);
        if (parent == nullptr)
        {
            Node *newRoot = new Node(deg, false);
            newRoot->children.push_back(this);

            parent = newRoot;
        }
        Node *bigNode = new Node(deg, smallNode->leaf);
        bigNode->parent = this;

        for (i = 0; i < children.size(); i++)
        {
            if (children[i] == smallNode)
            {
                break;
            }
        }
        children.resize(children.size() + 1);
        for (int j = nV; j >= i + 1; j--)
        {
            children[j + 1] = children[j];
        }
        children[i + 1] = bigNode;

        i = smallNode->nV;
        while (i > median)
        {
            bigNode->values[bigNode->nV] = smallNode->values[i];
            bigNode->nV++;
            smallNode->nV--;
            i--;
        }

        // Childmigration
        if (!smallNode->leaf)
        {
            for (i = 0; i + median + 1 < smallNode->children.size(); i++)
            {
                bigNode->children.push_back(smallNode->children[median + i + 1]);
                bigNode->children[i]->parent = bigNode;
            }
            smallNode->children.resize(smallNode->children.size() - i);
        }

        parent->splitChild(this, med);
    }
    else
    {
        std::cout << "fs1";
        std::cout << smallNode->leaf;
        std::cout << deg;
        Node *bigNode = new Node(deg, smallNode->leaf);
        std::cout << "fs2";
        bigNode->parent = this;

        int i = 0;
        for (i = 0; i < children.size(); i++)
        {
            if (children[i] == smallNode)
            {
                break;
            }
        }
        children.resize(children.size() + 1);
        for (int j = nV; j >= i + 1; j--)
        {
            children[j + 1] = children[j];
        }
        children[i + 1] = bigNode;

        addValToNode(smallNode->values[median]);

        i = smallNode->nV;
        while (i > median)
        {
            bigNode->values[bigNode->nV] = smallNode->values[i];
            bigNode->nV++;
            smallNode->nV--;
            i--;
        }

        // Childmigration
        if (!smallNode->leaf)
        {
            for (i = 0; i + median + 1 < smallNode->children.size(); i++)
            {
                bigNode->children.push_back(smallNode->children[median + i + 1]);
                bigNode->children[i]->parent = bigNode;
            }
            smallNode->children.resize(smallNode->children.size() - i);
        }
    }
}

void Node::addValToNode(int value)
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
    if (values[i + 1] == value)
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
