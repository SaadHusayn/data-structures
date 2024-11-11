#include<iostream>
#include"AVL.h"
using namespace std;

int main(){
    AVL<int> *edits = new AVL<int>(12);
    edits = insert(edits, 14);
    edits = insert(edits, 99);

    cout<<"\nTimestamps of edits in chronological order are: ";
    printTree(edits);
}