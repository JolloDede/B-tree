#include <iostream>
#include "..\src\btree.h"

using namespace std;

int main(){
    BTree tree(2,3);
    tree.newValue(4);
    // tree.printTree();
    tree.newValue(7);
    // tree.printTree();
    tree.newValue(11);
    tree.printTree();
    // tree.newValue(3);
    // tree.printTree();
}