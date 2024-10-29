#include<iostream>
#include"BST.h"

using namespace std;

int main(){

    BST *bt = new BST(1);

    for(int i=2;i<=10;i++){
        BST::insertNode(bt, i);
    }

    BST::traverseInOrder(bt);
    cout<<endl;

    BST::deleteNode(bt, 1);

    BST::traversePostOrder(bt);



}