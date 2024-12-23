#include<iostream>
using namespace std;

class AVL{
    public:
    int data;
    AVL *left;
    AVL *right;

    AVL(int _data=0, AVL *_left=nullptr, AVL *_right=nullptr){
        data= _data;
        left = _left;
        right = _right;
    }
};

void inorder(AVL *root){
    if(root != nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(AVL *root){
    if(root != nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(AVL *root){
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

AVL * insert(AVL *root, int data){
    if(root == nullptr) return new AVL(data);
    if(root->data == data) return root;
    if(root->data > data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

AVL *search(AVL *root, int data){
    if(root == nullptr || root->data == data) return root;
    if(root->data > data) return search(root->left, data);
    else search(root->right, data);
}

int getMinValue(AVL *root){
    if(root->left == nullptr) return root->data;
    else return getMinValue(root->left);
}

AVL *deleteNode(AVL *root, int data){
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

int inorderPredecessor(AVL *root, int data){
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

int inorderSuccessor(AVL *root, int data){
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
    AVL *root = new AVL(1);

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