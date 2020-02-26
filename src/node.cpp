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
            if (parent == NULL)
            {
                Node *newRoot = new Node(deg, false);
                newRoot->nV = 0;
                newRoot->parent = NULL;
                newRoot->children[0] = this;
                parent = newRoot;
            }
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
    if (nV == deg - 1)
    {
        int i = nV - 1;
        while (i >= 0 && values[i] > smallNode->values[median])
        {
            values[i + 1] = values[i];
            i--;
        }
        values[i + 1] = smallNode->values[median];
        int med = sizeof(values) / sizeof(*values);
        if (parent == NULL)
        {
            Node *newRoot = new Node(deg, false);
            newRoot->nV = 0;
            newRoot->parent = NULL;
            newRoot->children[0] = this;
            parent = newRoot;
        }
        parent->splitChild(this, med);

        Node *bigNode = new Node(deg, smallNode->leaf);
        bigNode->nV = 0;
        bigNode->parent = this;

        for (i = 0; i < sizeof(children) / sizeof(*children); i++)
        {
            if (children[i] == smallNode)
            {
                break;
            }
        }
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
    }
    else
    {
        Node *bigNode = new Node(deg, smallNode->leaf);
        bigNode->nV = 0;
        bigNode->parent = this;

        int i;
        for (i = 0; i < sizeof(children) / sizeof(*children); i++)
        {
            if (children[i] == smallNode)
            {
                break;
            }
        }
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
            // If the smallNod ehas more than deg of children then let the 2 smallchildrne to the small node and the big children to the bignode
            // std::cout << sizeof(smallNode->children)/sizeof(Node*);
            // if (sizeof(smallNode->children)/sizeof(*smallNode->children) )
            // {
            //     /* code */
            // }
            
            for (i = 0; i <= sizeof(smallNode->children) / sizeof(*smallNode->children); i++)
            {
                bigNode->children[i] = smallNode->children[median + i];
                bigNode->children[i]->parent = bigNode;
                smallNode->children[median + i] = nullptr;
            }
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
