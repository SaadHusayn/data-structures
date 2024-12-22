#ifndef BST_H

#define BST_H

//insertion, deletion, searching, 3 traversals, ascending, descending, inorder predecessor/successor

#include<iostream>


class BSTNode{
    public:
        int key;
        BSTNode *left;
        BSTNode *right;
    

    BSTNode(int _key=0, BSTNode *_left=nullptr, BSTNode *_right=nullptr){
        key = _key;
        left = _left;
        right = _right;
    }
}

class BST{
    public:
    static BSTNode* insert(BSTNode *root, int key){
        if(root ==  nullptr) return new BSTNode(key);
        if(root->key == key) return root;
        if(key > root->key) root->right = BST::insert(root->right, key);
        else root->left = BST::insert(root->left, key);

        return root;
    }

    static BSTNode * search(BSTNode *root, int key){
        if(root==nullptr) return 
        if(root->key == key) return root;
    }
}


#endif