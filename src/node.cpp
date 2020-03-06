#include "node.h"

// Constructor Init size of children and values
Node::Node(int deg, bool leaf)
{
    Node::leaf = leaf;
    Node::deg = deg;
    values.resize(deg - 1);
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
            int med = values.size() / 2;
            if (parent == nullptr)
            {
                Node *newRoot = new Node(deg, false);
                newRoot->children.push_back(this);

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
        int med = values.size() / 2;
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
        Node *bigNode = new Node(deg, smallNode->leaf);
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
        if (i < children.size())
        {
            children[i]->printInOrder();
        }
    }
}

Node *Node::find(int value)
{
    int i = nV - 1;
    while (i >= 0 && values[i] > value)
    {
        i--;
    }
    if (values[i] == value)
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

void Node::deleteValue(int value)
{

}

// 2a
void Node::deleteFromLeaf(Node *_node, bool bigger_node)
{
    int x = parent->getChildIndex(this);
    values[nV] = parent->values[x];
    nV++;

    if (bigger_node)
    {
        parent->values[x] = _node->values[0];
        for (int i = 0; i < _node->nV; i++)
        {
            _node->values[i] = _node->values[i + 1];
        }
    }
    else
    {
        parent->values[x] = _node->values[_node->nV - 1];
    }

    _node->nV--;

    if (_node->nV == 0)
    {
        if (bigger_node)
        {
            parent->children.erase(parent->children.begin()+x+1);
        }
        else
        {
            parent->children.erase(parent->children.begin()+x-1);
        }
        
        delete _node;
    }
    
}

// 2b
void Node::merge(Node *node)
{
    int x = parent->getChildIndex(this);
    values[nV] = parent->values[x];
    parent->children.erase(parent->children.begin() + x + 1);

    while (x < parent->nV)
    {
        parent->values[x] = parent->values[x + 1];
        x++;
    }
    nV++;
    parent->nV--;

    for (int i = 0; i < node->nV; i++)
    {
        values[nV] = node->values[i];
        nV++;
        node->nV--;
    }

    delete node;
}

int Node::getChildIndex(Node *node)
{
    for (int i = 0; i < children.size(); i++)
    {
        if (node == children[i])
        {
            return i;
        }
    }
    std::cout << std::endl
              << "Error cant find child" << std::endl;
    return -1;
}
