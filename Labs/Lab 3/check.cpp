#include<iostream>
#include"DLL.h"
using namespace std;

int main(){
    
    // Node *n = new Node(99);

    DLL *List = new DLL();
    List->appendNode(9);
    List->prependNode(1);
    List->appendNode(39);

    List->display(List->head);

    List->insertAt(22, 222);

    List->display(List->head);

    List->deleteNode(9);

    List->display(List->head);


}