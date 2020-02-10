#include <iostream>
#include "..\src\btree.h"

using namespace std;

int main(){
    btree tree(1,3);
    tree.newValue(1);
    cout << sizeof(tree.rootNode.children);
}