#include <iostream>
#include "..\src\btree.h"

using namespace std;

// Here is the testmain
int main(){
    // A Btree with a minimum degree of 3
    BTree tree(3);

    tree.newValue(4);
    tree.newValue(7);
    tree.newValue(11);
    tree.newValue(3);
    tree.newValue(80);
    tree.newValue(29);
    tree.newValue(14);
    // tree.newValue(2);
    // tree.newValue(10);
    // The tree gets printed in Order
    tree.printTree();
}