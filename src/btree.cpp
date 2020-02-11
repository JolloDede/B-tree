#include "btree.h"

btree::btree(int _amountValues, int _degree)
{
    valueAmount = _amountValues;
    degree = _degree;
    rootNode = NULL;
}

void btree::xorSwap(int *x, int *y)
{
    if (x != y)
    { //ensure that memory locations are different
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

void btree::newValue(int value){
    if (rootNode == NULL)
    {
        nodeList.push_back(node(valueAmount,degree, true));
        rootNode = &nodeList[0];
        rootNode->values[0] = value;
        rootNode->nV = 1;
    } else{

    }
}

void btree::insert(int value){
    
}

void btree::printTree(){
    for (int i = 0; i < nodeList.size(); i++)
    {
       std::cout << "node { ";
       for (int j = 0; j < valueAmount; j++)
       {
           std::cout << "[" <<nodeList[i].values[j] << "] ";
       }
       std::cout << "}" << std::endl;
    }  
}