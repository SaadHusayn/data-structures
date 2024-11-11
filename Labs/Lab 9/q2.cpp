#include<iostream>
#include"AVL.h"
using namespace std;



int main(){

    AVL<int> *root = new AVL<int>(2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 66);
    root = insert(root, -4);

    cout<<"Minimun from the AVL: "<<getMin(root)<<"\nMaximum from the AVL: "<<getMax(root)<<endl;

}