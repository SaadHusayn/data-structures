#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<iostream>


class BinaryTree{
    public:
    int val;
    BinaryTree *leftChild;
    BinaryTree *rightChild;


    BinaryTree(int _val=0, BinaryTree *_leftChild=nullptr, BinaryTree *_rightChild=nullptr){
        val = _val;
        leftChild = _leftChild;
        rightChild = _rightChild;
    }


    
};

void traversePreOrder(BinaryTree *node){
    if(node != nullptr){
        std::cout<<" "<<node->val;
        traversePreOrder(node->leftChild);
        traversePreOrder(node->rightChild);
    }
}

void traverseInOrder(BinaryTree *node){
    if(node != nullptr){
        traverseInOrder(node->leftChild);
        std::cout<<" "<<node->val;
        traverseInOrder(node->rightChild);
    }
}

void traversePostOrder(BinaryTree *node){
    if(node != nullptr){
        traversePostOrder(node->leftChild);
        traversePostOrder(node->rightChild);
        std::cout<<" "<<node->val;
    }
}

bool find(BinaryTree *node, int key){
    if(node == nullptr) return false;
    if(node->val == key) return true;

    if(node->val > key) return find(node->leftChild, key);
    return find(node->rightChild, key);
}

void insert(BinaryTree *&node, int data){
    if(node == nullptr) {node = new BinaryTree{data}; return;}
    if(node->val == data) return;

    if(node->val > data) insert(node->leftChild, data);
    else insert(node->rightChild, data);
}

#endif
