#include "node.h"

node::node(int amountValues, int deg, bool leaf){
    node::leaf = leaf;

    values = new int[amountValues];
    children = new node *[deg];

    nV = 0;
}
