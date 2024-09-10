#include<iostream>
#include "CLL.h"

using namespace std;

int main(){
    CLL List;
    List.insertAtEnd(9);
    List.insertAtEnd(21);
    List.insertAtFront(2);
    List.display();
}