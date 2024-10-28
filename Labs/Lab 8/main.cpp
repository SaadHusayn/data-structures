#include<iostream>
#include"BinaryTree.h"

using namespace std;

int main(){

    BinaryTree *root = new BinaryTree{4, new BinaryTree{2, new BinaryTree{0}, new BinaryTree{3}}, new BinaryTree{6, new BinaryTree{5}, new BinaryTree{9}}};

    traverseInOrder(root);
    cout<<endl;
    insert(root, 7);
    traverseInOrder(root);
    cout<<endl;

}