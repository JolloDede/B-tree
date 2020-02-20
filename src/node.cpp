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

}

// Splits the child of de current node and decides where the value goes
void Node::splitChild(int i, Node *smallNode, int value)
{

}

// The Nodes print itself with recursion starting at the rootNode
void Node::printInOrder()
{
}
