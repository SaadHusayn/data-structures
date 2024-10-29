#ifndef BST_H
#define BST_H

#include <iostream>
#include<algorithm>

class BST
{
public:
    int val;
    BST *leftChild;
    BST *rightChild;

    BST(int _val = 0, BST *_leftChild = nullptr, BST *_rightChild = nullptr)
    {
        val = _val;
        leftChild = _leftChild;
        rightChild = _rightChild;
    }

    static void traversePreOrder(BST *node)
    {
        if (node != nullptr)
        {
            std::cout << " " << node->val;
            traversePreOrder(node->leftChild);
            traversePreOrder(node->rightChild);
        }
    }

    static void traverseInOrder(BST *node)
    {
        if (node != nullptr)
        {
            traverseInOrder(node->leftChild);
            std::cout << " " << node->val;
            traverseInOrder(node->rightChild);
        }
    }

    static void traversePostOrder(BST *node)
    {
        if (node != nullptr)
        {
            traversePostOrder(node->leftChild);
            traversePostOrder(node->rightChild);
            std::cout << " " << node->val;
        }
    }

    static BST* find(BST *node, int key)
    {
        if (node == nullptr || node->val == key)
            return node;
  

        if (node->val > key)  return find(node->leftChild, key);
        return find(node->rightChild, key);
    }

    static void insertNode(BST *&node, int data)
    {
        if (node == nullptr)
        {
            node = new BST{data};
            return;
        }


        if (node->val > data)
            insertNode(node->leftChild, data);
        else
            insertNode(node->rightChild, data);
    }



    static void deleteNode(BST *&node, int _val){
        if(node == nullptr) return; //not found

        if(node->val > _val) deleteNode(node->leftChild, _val);
        else if(node->val < _val) deleteNode(node->rightChild, _val);


        else{
            // now checking if it has no childs
            if(node->leftChild == nullptr && node->rightChild == nullptr){
                delete node;
                node = nullptr;
                return;
            }

            // now checking if it has one child
            if(node->leftChild == nullptr && node->rightChild != nullptr){
                auto tmp = node;
                node = node->rightChild;
                delete tmp;
                return;
            }

            if(node->leftChild != nullptr && node->rightChild == nullptr){
                auto tmp = node;
                node = node->leftChild;
                delete tmp;
                return;
            }

            //now the node will have both left and right children

            //first checking if it has no right left successor
            if(node->rightChild->leftChild == nullptr){
                auto tmp = node;
                node = node->rightChild;
                delete tmp;
                return;
            }

            //now the node has right left successor
            BST *& successor = getSuccessor(node->rightChild);
            auto tmp = successor;
            std::swap(node->val, successor->val);
            successor = successor->rightChild;
            delete tmp;

        }

        
    }

    static BST *& getSuccessor(BST *&node){
        return (node->leftChild == nullptr) ? node : getSuccessor(node->leftChild);
    }
};

#endif
