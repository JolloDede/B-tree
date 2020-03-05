#include <iostream>
#include "..\src\btree.h"

using namespace std;

void testInsertion(BTree *tree);

// Here is the testmain
int main(){
    // A Btree with a minimum degree of 3
    BTree tree(3);
    testInsertion(&tree);
    // The tree gets printed in Order
    tree.printTree();
    tree.printInOrder();
    cout << endl;
    cout << "Search:" << endl;
    cout << tree.search(7);
    cout << endl;
    cout << "Delete value:" << endl;
    cout << tree.deleteValue(81);
    cout << endl;
    tree.printTree();
    tree.printInOrder();
    cout << endl << "End";
}

void testInsertion(BTree *tree){
    tree->newValue(4);
    tree->newValue(7);
    tree->newValue(11);
    tree->newValue(3);
    tree->newValue(80);
    tree->newValue(29);
    tree->newValue(14);
    tree->newValue(2);
    tree->newValue(10);

    tree->newValue(100);
    tree->newValue(60);
    tree->newValue(13);
    tree->newValue(1);
    tree->newValue(15);
    tree->newValue(90);
    tree->newValue(81);
    tree->newValue(33);
    tree->newValue(45);
    tree->newValue(110);
}