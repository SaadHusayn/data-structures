#include <iostream>
using namespace std;

class Record {
    public:
    int id;
    string name;
    int age;


    Record(int _id=0, string _name="", int _age=0) : id(_id), name(_name), age(_age) {}
};

class BST
{
public:
    Record rec;
    BST *left;
    BST *right;

    BST(Record _rec = Record(), BST *_left = nullptr, BST *_right = nullptr)
    {
        rec = _rec;
        left = _left;
        right = _right;
    }
};

BST * insert(BST *tree, int ID, string name, int age)
{
    if (tree == nullptr)
    {
        return new BST(Record{ID, name, age});
    }

    if(tree->rec.id == ID) return tree;

    if (ID < tree->rec.id)
        tree->left = insert(tree->left, ID, name, age);
    else
        tree->right = insert(tree->right, ID, name, age);

    return tree;
}

BST *find(BST *tree, int ID)
{
    if (tree == nullptr || tree->rec.id == ID)
        return tree;

    if (ID < tree->rec.id)
        find(tree->left, ID);
    else
        find(tree->right, ID);
}

void preOrder(BST *tree)
{
    if (tree != nullptr)
    {
        cout << "ID: " << tree->rec.id << ", Name: " << tree->rec.name << ", Age: " << tree->rec.age << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(BST *tree)
{
    if (tree != nullptr)
    {
        inOrder(tree->left);
        cout << "ID: " << tree->rec.id << ", Name: " << tree->rec.name << ", Age: " << tree->rec.age << endl;
        inOrder(tree->right);
    }
}

void postOrder(BST *tree)
{
    if (tree != nullptr)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << "ID: " << tree->rec.id << ", Name: " << tree->rec.name << ", Age: " << tree->rec.age << endl;
    }
}

void inOrderDescending(BST *tree)
{
    if (tree != nullptr)
    {
        inOrderDescending(tree->right);
        cout << "ID: " << tree->rec.id << ", Name: " << tree->rec.name << ", Age: " << tree->rec.age << endl;
        inOrderDescending(tree->left);
    }
}

int getMin(BST *tree){
    if(tree->left == nullptr) return tree->rec.id;
    return getMin(tree->left);
}

BST * deleteNode(BST *&tree, int ID){
    if(tree == nullptr) return tree;

    if(ID < tree->rec.id) tree->left = deleteNode(tree->left, ID);
    else if (ID > tree->rec.id) tree->right = deleteNode(tree->right, ID);
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
        auto minRecord = find(tree, ID);
        tree->rec = minRecord->rec;
        tree->right = deleteNode(tree->right, min);
    }

    return tree;
}

int inOrderPredecessor(BST *tree,int ID){
    int Predecessor = -1;

    while(tree!=nullptr){
        if(tree->rec.id < ID) {
            Predecessor = tree->rec.id;
            tree = tree->right;
        }else{
            tree = tree->left;
        }
    }

    return Predecessor;
}

int inOrderSuccessor(BST *tree,int ID){
    int successor = -1;

    while(tree!=nullptr){
        if(tree->rec.id >= tree->rec.id) {
            tree = tree->right;
        }else{
            successor = tree->rec.id;
            tree = tree->left;
        }
    }

    return successor;
}

int main()
{
    BST *tree = new BST(1);

    tree = insert(tree, 1, "Saad", 18);
    tree = insert(tree, 2, "Sabih",  19);
    tree = insert(tree, 3, "Tanzeel", 20);

    inOrder(tree);

    tree = deleteNode(tree, 1);

    cout<<endl;
    tree = insert(tree, 1, "Tabish", 20);

    inOrder(tree);
    cout<<endl;
}