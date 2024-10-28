#include<iostream>
#include"BinaryTree.h"
#include"DLL.h"

using namespace std;

//well use inorder traversal logic
void makeListSorted(BinaryTree *root, DLL *head){
    if(root!=nullptr){
        makeListSorted(root->leftChild, head);
        head->appendNode(root->val);
        makeListSorted(root->rightChild, head);
    }
}

int main(){
    BinaryTree *root = new BinaryTree{4, new BinaryTree{2, new BinaryTree{0}, new BinaryTree{3}}, new BinaryTree{6, new BinaryTree{5}, new BinaryTree{9}}};

    DLL *dll = new DLL();
    makeListSorted(root, dll);

    display(dll->head);
}