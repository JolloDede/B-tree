#include <iostream>
#include <stdlib.h>

struct node
{
    int left, right;
    node *parent;
    node *children[];

    node(int x);
    node();
};