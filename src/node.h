#include <iostream>
#include <stdlib.h>

struct node
{
    int *values;
    int nV;
    node *parent;
    node **children;
    bool leaf;

    node(int amountValues, int deg, bool leaf);
    node();
};