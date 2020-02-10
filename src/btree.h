#include <iostream>
#include "node.h"

class btree
{
    bool initValue;
    node nodeList[];
    int nCount;

    public:
        node rootNode;
        btree(int startValue, int numberOfChildren);
        void newValue(int value);
        void insert(int value, node *nodeNow);
        void placeValue(int value);
};