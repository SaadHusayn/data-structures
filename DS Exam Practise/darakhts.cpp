#include <iostream>
using namespace std;

class BT
{
public:
    int val;
    BT *left;
    BT *right;

    BT(int _val = 0, BT *_left = nullptr, BT *_right = nullptr)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

BT * insert(BT *tree, int val)
{
    if (tree == nullptr)
    {
        return new BT(val);
    }

    if (val < tree->val)
        tree->left = insert(tree->left, val);
    else
        tree->right = insert(tree->right, val);

    return tree;
}

BT *find(BT *tree, int val)
{
    if (tree == nullptr || tree->val == val)
        return tree;

    if (val < tree->val)
        find(tree->left, val);
    else
        find(tree->right, val);
}

void preOrder(BT *tree)
{
    if (tree != nullptr)
    {
        cout << tree->val << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(BT *tree)
{
    if (tree != nullptr)
    {
        inOrder(tree->left);
        cout << tree->val << " ";
        inOrder(tree->right);
    }
}

void postOrder(BT *tree)
{
    if (tree != nullptr)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->val << " ";
    }
}

void inOrderDescending(BT *tree)
{
    if (tree != nullptr)
    {
        inOrderDescending(tree->right);
        cout << tree->val << " ";
        inOrderDescending(tree->left);
    }
}

int getMin(BT *tree){
    if(tree->left == nullptr) return tree->val;
    return getMin(tree->left);
}

BT * deleteNode(BT *&tree, int val){
    if(tree == nullptr) return tree;

    if(val < tree->val) tree->left = deleteNode(tree->left, val);
    else if (val > tree->val) tree->right = deleteNode(tree->right, val);
    else{
        

        //0 child
        if(tree->left == nullptr && tree->right == nullptr){
            delete tree;
            return nullptr;
        }

        //1 child
        if(tree->left == nullptr && tree->right != nullptr){
            auto tmp = tree->right;
            delete tree;
            return tmp;
        }

        if(tree->left != nullptr && tree->right == nullptr){
            auto tmp = tree->left;
            delete tree;
            return tmp;
        }

        //2 child
        int min = getMin(tree->right);
        tree->val = min;
        tree->right = deleteNode(tree->right, min);
    }

    return tree;
}

int inOrderPredecessor(BT *tree,int v){
    int Predecessor = -1;

    while(tree!=nullptr){
        if(tree->val < v) {
            Predecessor = tree->val;
            tree = tree->right;
        }else{
            tree = tree->left;
        }
    }

    return Predecessor;
}

int inOrderSuccessor(BT *tree,int v){
    int successor = -1;

    while(tree!=nullptr){
        if(v >= tree->val) {
            tree = tree->right;
        }else{
            successor = tree->val;
            tree = tree->left;
        }
    }

    return successor;
}

int main()
{
    BT *tree = new BT(1);
    for (int i = 2; i <= 10; i++)
        insert(tree, i);

    tree = insert(tree, 21);
    tree = insert(tree, 20);
    tree = insert(tree, 6);

    tree = deleteNode(tree, 1);

    inOrder(tree);
    cout<<endl;
    cout<<"Inorder successor of 8 is "<<inOrderSuccessor(tree, 8);


    cout<<endl;
    cout<<"Inorder successor of 8 is "<<inOrderPredecessor(tree, 8);
}