#include <iostream>
#include "..\src\btree.h"

using namespace std;

int main(){
    BTree tree(2,3);
    tree.newValue(4);
    tree.newValue(7);
    tree.newValue(11);
    tree.newValue(3);
    tree.newValue(80);
    tree.newValue(29);
    tree.newValue(14);
    tree.newValue(2);
    tree.newValue(10);
    tree.printTree();
}