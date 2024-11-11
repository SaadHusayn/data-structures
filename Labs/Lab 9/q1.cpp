#include<iostream>
#include"AVL.h"
using namespace std;

int main(){
    AVL<int> *root = new AVL<int>(1);
    root = insert(root, 4);
    root = insert(root, 9);

    printTree(root);
    cout<<"\nAfter deleting 4, the tree is ";

    root = deleteNode(root, 4);
    cout<<"\n";

    printTree(root);

    cout<<"\n14 exists in the tree: ";

    auto tmp = search(root, 14);
    if(tmp==nullptr)cout<<"No";
    else cout<<"Yes";

}