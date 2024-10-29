#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<iostream>


class BST{
    public:
    int val;
    BST *leftChild;
    BST *rightChild;


    BST(int _val=0, BST *_leftChild=nullptr, BST *_rightChild=nullptr){
        val = _val;
        leftChild = _leftChild;
        rightChild = _rightChild;
    }


    
};

void traversePreOrder(BST *node){
    if(node != nullptr){
        std::cout<<" "<<node->val;
        traversePreOrder(node->leftChild);
        traversePreOrder(node->rightChild);
    }
}

void traverseInOrder(BST *node){
    if(node != nullptr){
        traverseInOrder(node->leftChild);
        std::cout<<" "<<node->val;
        traverseInOrder(node->rightChild);
    }
}

void traversePostOrder(BST *node){
    if(node != nullptr){
        traversePostOrder(node->leftChild);
        traversePostOrder(node->rightChild);
        std::cout<<" "<<node->val;
    }
}

bool find(BST *node, int key){
    if(node == nullptr) return false;
    if(node->val == key) return true;

    if(node->val > key) return find(node->leftChild, key);
    return find(node->rightChild, key);
}

void insert(BST *&node, int data){
    if(node == nullptr) {node = new BST{data}; return;}
    if(node->val == data) return;

    if(node->val > data) insert(node->leftChild, data);
    else insert(node->rightChild, data);
}

#endif
