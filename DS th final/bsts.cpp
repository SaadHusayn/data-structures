#include<iostream>
using namespace std;

class BST{
    public:
    int data;
    BST *left;
    BST *right;

    BST(int _data=0, BST *_left=nullptr, BST *_right=nullptr){
        data= _data;
        left = _left;
        right = _right;
    }
};

void inorder(BST *root){
    if(root != nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(BST *root){
    if(root != nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(BST *root){
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

BST * insert(BST *root, int data){
    if(root == nullptr) return new BST(data);
    if(root->data == data) return root;
    if(root->data > data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

BST *search(BST *root, int data){
    if(root == nullptr || root->data == data) return root;
    if(root->data > data) return search(root->left, data);
    else search(root->right, data);
}

int getMinValue(BST *root){
    if(root->left == nullptr) return root->data;
    else return getMinValue(root->left);
}

BST *deleteNode(BST *root, int data){
    if(root == nullptr) return root;
    if(root->data > data) root->left = deleteNode(root->left, data);
    else if(root->data < data) root->right = deleteNode(root->right, data);
    else{
        //0 childs 
        if(root->left == nullptr && root->right == nullptr) {
            delete root ;
            root = nullptr;
            return root;
        }

        //1 child
        if(root->left == nullptr && root -> right != nullptr){
            auto tmp = root->right;
            delete root;
            root = tmp;
            return root;
        }

        if(root->left != nullptr && root -> right == nullptr){
            auto tmp = root->left;
            delete root;
            root = tmp;
            return root;
        }

        //2 childs
        int successor  = getMinValue(root->right);
        root->data = successor;
        root->right = deleteNode(root->right, successor);
    }
}

int inorderPredecessor(BST *root, int data){
    int predecessor = -1;

    while(root != nullptr){
        if(root->data < data){
            predecessor = root->data;
            root = root -> right;
        }else{
            root = root->left;
        }
    }

    return predecessor;
}

int inorderSuccessor(BST *root, int data){
    int successor = -1;
    while(root != nullptr){
        if(root->data > data){
            successor = root->data;
            root = root -> left;
        }else{
            root = root->right;
        }
    }

    return successor;
}

int main(){
    BST *root = new BST(1);

    inorder(root);
    cout<<endl;

    for(int i=2;i<=10;i++) {
        root = insert(root, i);
    }

    inorder(root);
    cout<<endl;

    root = deleteNode(root, 1);
    root = deleteNode(root, 6);
    root = deleteNode(root, 11);

    inorder(root);
    cout<<endl;

    cout<<inorderPredecessor(root, 7)<<endl;
    cout<<inorderSuccessor(root, 7)<<endl;
}