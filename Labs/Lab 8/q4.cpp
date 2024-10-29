#include<iostream>
#include"BST.h"
using namespace std;

void mergeBST(BST *&BST1, BST *BST2){
    if(BST2 != nullptr){
        BST::insertNode(BST1, BST2->val);
        mergeBST(BST1, BST2->leftChild);
        mergeBST(BST1, BST2->rightChild);
    }
}
int main(){
    BST *BST1 = new BST(5);
    BST::insertNode(BST1, 3);
    BST::insertNode(BST1, 6);
    BST::insertNode(BST1, 2);
    BST::insertNode(BST1, 4);

    cout<<"BST1 is : ";
    BST::traverseInOrder(BST1);
    cout<<endl;

    BST *BST2 = new BST(2);
    BST::insertNode(BST2, 1);
    BST::insertNode(BST2, 3);
    BST::insertNode(BST2, 7);
    BST::insertNode(BST2, 6);

    cout<<"BST2 is : ";
    BST::traverseInOrder(BST2);
    cout<<endl;

    mergeBST(BST1, BST2);
    cout<<"Merged BST1 is : ";
    BST::traverseInOrder(BST1);
    cout<<endl;
}