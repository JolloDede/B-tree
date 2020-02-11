#include <iostream>
#include "..\src\btree.h"

using namespace std;

int main(){
    btree tree(2,3);
    tree.newValue(4);
    tree.newValue(7);
    tree.printTree();
}