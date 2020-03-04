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

bool BTree::deleteValue(int value)
{
    bool found;
    Node *node = rootNode->find(value);

    for (int i = 0; i < node->nV; i++)
    {
        if (value == node->values[i])
        {
            found = true;
            break;
        }
    }
    // if found delete and rearange
    if (found)
    {
        if (node->leaf) // Case 2
        {
            if (node->nV > 1) // 1 only for deg 3
            {
                // Just delete the Value
                int i;
                for (i = 0; i < node->nV; i++)
                {
                    if (node->values[i] >= value)
                    {
                        node->values[i] = node->values[i + 1];
                    }
                }
                node->nV--;
            }
            else
            {
                // Delete this value
                int i;
                for (i = 0; i < node->nV; i++)
                {
                    if (node->values[i] == value)
                    {
                        node->values[i] = NULL;
                        node->nV--;
                        break;
                    }
                }

                Node *parent = node->parent;
                int ii = parent->getChildIndex(node);
                int yChildPos;
                if (ii == parent->children.size() - 1)
                {
                    yChildPos = ii - 1;
                }
                else
                {
                    yChildPos = ii + 1;
                }
                Node *yChild = parent->children[yChildPos];

                if (yChild->nV == 1/* only for deg 3 */)// Case 2a
                {
                    
                    /* code */
                }
                else // Case 2b
                {
                    if (ii < yChildPos)
                    {
                        node->merge(yChild);
                    }
                    else
                    {
                        yChild->merge(node);
                    }
                }
                                
            }
        }
        else // Case 3
        {
            /* code */
        }
        

        // node->deleteValue(value);
    }

    return found;
}

// Main function Where the tree gets printed to the commandline
void BTree::printTree()
{
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
    std::cout << rootNode->children[1]->children[0]->children.size();
    std::cout << std::endl
              << "Child 2 Child 2: ";
    std::cout << std::endl
              << rootNode->children[1]->children[1]->nV << std::endl;
    for (int i = 0; i < rootNode->children[1]->children[1]->nV; i++)
    {
        std::cout << rootNode->children[1]->children[1]->values[i] << " ";
    }
    std::cout << rootNode->children[1]->children[1]->children.size();
    // std::cout << std::endl
    //           << "Child 2 Child 3: ";
    // std::cout << std::endl
    //           << rootNode->children[1]->children[2]->nV << std::endl;
    // for (int i = 0; i < rootNode->children[1]->children[2]->nV; i++)
    // {
    //     std::cout << rootNode->children[1]->children[2]->values[i] << " ";
    // }

    // std::cout << std::endl
    //           << "Rootchild 3: ";
    // std::cout << std::endl
    //           << rootNode->children[2]->nV << std::endl;
    // for (int i = 0; i < rootNode->children[2]->nV; i++)
    // {
    //     std::cout << rootNode->children[2]->values[i] << " ";
    // }
    // std::cout << std::endl
    //           << "Rootchild 3 Child 1: ";
    // std::cout << std::endl
    //           << rootNode->children[2]->children[0]->nV << std::endl;
    // for (int i = 0; i < rootNode->children[2]->children[0]->nV; i++)
    // {
    //     std::cout << rootNode->children[2]->children[0]->values[i] << " ";
    // }
    // std::cout << std::endl
    //           << "Rootchild 3 Child 2: ";
    // std::cout << std::endl
    //           << rootNode->children[2]->children[1]->nV << std::endl;
    // for (int i = 0; i < rootNode->children[2]->children[1]->nV; i++)
    // {
    //     std::cout << rootNode->children[2]->children[1]->values[i] << " ";
    // }
}

void BTree::printInOrder()
{
    std::cout << std::endl
              << std::endl;
    rootNode->printInOrder();
}
