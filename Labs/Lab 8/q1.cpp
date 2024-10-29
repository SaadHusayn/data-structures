#include <iostream>
#include "BST.h"
#include "DLL.h"

using namespace std;

// well use inorder traversal logic
void makeListSorted(BST *root, DLL *head)
{
    if (root != nullptr)
    {
        makeListSorted(root->leftChild, head);
        head->appendNode(root->val);
        makeListSorted(root->rightChild, head);
    }
}

int main()
{
    // creating a bst with 10 nodes from 1 to 10
    BST *root = new BST(1);
    for (int i = 2; i <= 10; i++)
    {
        BST::insertNode(root, i);
    }

    DLL *dll = new DLL();
    makeListSorted(root, dll);

    DLL::display(dll->head);
}