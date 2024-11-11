#ifndef AVL_H
#define AVL_H

#include<iostream>

template<typename T>
class AVL{
    public:
    T key;
    AVL *left;
    AVL *right;
    int height;
    
    AVL(T _key){
        key = _key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }


};

int max(int a, int b){ return (a > b)?a:b;}

template<typename T>
int getHeight(AVL<T> *root){
    if(root == nullptr) return 0;

    return root->height;
}

template<typename T>
AVL<T>* rightRotate(AVL<T> *root){
    auto tmp = root->left;
    root->left = tmp->right;
    tmp->right  = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

    return tmp;
}

template<typename T>
AVL<T>* leftRotate(AVL<T> *root){
    auto tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));

    return tmp;
}
template<typename T>
int getMin(AVL<T> *root){
    if(root->left == nullptr) return root->key;
    return getMin(root->left);
}

template<typename T>
int getMax(AVL<T> *root){
    if(root->right == nullptr) return root->key;
    return getMax(root->right);
}

template<typename T>
int getBalanceFactor(AVL<T> *root){
    if(root == nullptr) return 0;

    return getHeight(root->left) - getHeight(root->right);
}

template<typename T>
void printTree(AVL<T> *root){
    if(root != nullptr){
        printTree(root->left);
        std::cout << root->key << " ";
        printTree(root->right);
    }
}

template<typename T>
AVL<T> *balancedAVL(AVL<T> *root){
    int balance_factor = getBalanceFactor(root);

    if(balance_factor > 1){
        //left imbalance
        if(getBalanceFactor(root->left)>=0){
            //LL imbalance
            return rightRotate(root);
        }else{
            //LR imbalance
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }else if(balance_factor < -1){
        //right imbalance
        if(getBalanceFactor(root->right)<=0){
            //RR imbalance
            return leftRotate(root);
        }else{
            //RL imbalance
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }else return root;
}

template<typename T>
AVL<T>* search(AVL<T> *root, int key){
    if(root == nullptr || root->key == key) return root;

    if(key < root->key) return search(root->left, key);
    else return search(root->right, key);
}

template<typename T>
AVL<T>* insert(AVL<T>* root, int key){
    if(root == nullptr) return new AVL<T>(key);

    if(root->key == key) return root;

    if(key < root->key) root->left = insert(root->left, key);
    else if(key > root->key) root->right = insert(root->right, key);

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    return balancedAVL(root);

}

template<typename T>
AVL<T>* deleteNode(AVL<T> *root, int key){
    if(root == nullptr) return nullptr;

    if(key < root->key) root->left = deleteNode(root->left, key);
    else if(key > root->key) root->right = deleteNode(root->right, key);
    else{
        //0 child case
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }

        //1 child case
        if(root->left != nullptr && root->right == nullptr){
            auto tmp = root->left;
            delete root;
            return tmp;
        }

        if(root->right != nullptr && root->left == nullptr){
            auto tmp = root->right;
            delete root;
            return tmp;
        }

        //2 childs
        auto predecessor_value = getMin(root->right);
        root->key = predecessor_value;
        root->right = deleteNode(root->right, predecessor_value);
    }

    //updating the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    return balancedAVL(root);
}

#endif