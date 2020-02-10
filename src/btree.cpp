#include "btree.h"

btree::btree(int startValue, int numberOfChildren)
{
    rootNode.left = startValue;
    initValue = true;
    nCount = 1;
    nodeList[nCount-1] = rootNode;
    rootNode.children[numberOfChildren];
}

void btree::newValue(int value)
{
    std::cout << "left: " << rootNode.left << std::endl
              << "right: " << rootNode.right << std::endl;

    if (initValue)
    {
        if (value == rootNode.left)
        {
           return;
        }
        if (value > rootNode.left)
        {
            rootNode.right = value;
        }else{
            rootNode.right = rootNode.left;
            rootNode.left = value;
        }
        initValue = false;
        return;
    }
    insert(value, &rootNode);
}

void btree::insert(int value, node *nodeNow)
{    
    if (value == nodeNow->left || value == nodeNow->right)
    {
        return;
    }
    if (value < nodeNow->left)
    {
        nCount++;
        nodeList[nCount-1] = node(nodeNow->left);
    }else
    if (value > nodeNow->right)
    {
        nCount++;
        nodeList[nCount-1] = node(nodeNow->right);
    }
    else
    {
        nCount++;
        nodeList[nCount-1] = node(value);
    }
}

void btree::placeValue(int value){

}