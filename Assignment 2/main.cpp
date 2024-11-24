#include<iostream>
#include "RECORD_AVL.h"
#include "RECORD_BST.h"
#include "RECORD_BTREE.h"

using namespace std;

int main(){
    AVL *avl_database = new AVL();
    BST *bst_database = new BST();
    BTree *btree_database = new BTree(3);


    Record entry(1, "Saad", 19);

    btree_database->insert(entry);
    avl_database->insert(entry);
    bst_database->insert(entry);

    btree_database->insert(Record(2, "Babar", 30));
    avl_database->insert(Record(2, "Babar", 30));
    bst_database->insert(Record(2, "Babar", 30));

    avl_database->remove(2);

    btree_database->traverse();
    avl_database->print();
    bst_database->inOrder();


}