#include<iostream>
#include<chrono>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include "RECORD_AVL.h"
#include "RECORD_BST.h"
#include "RECORD_BTREE.h"


using namespace std;

int main(){
    BTree *table = new BTree(3);

    table->insert(Record(1, "Saad", 43));
    table->insert(Record(2, "S2aad", 43));
    table->insert(Record(3, "3aad", 43));
    table->insert(Record(4, "Sa5ad", 43));
    table->traverse(); 

    table->search(4);

    table->remove(1);
    table->remove(4);
    table->remove(2);

    table->traverse();
}