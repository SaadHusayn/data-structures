#include<iostream>
#include "StackLL.h"
using namespace std;

int main(){
    Stack S;

    S.push(43);
    S.push(433);
    S.push(43444);
    S.push(4344432);
    
    S.printStack();

    cout<<S.pop()<<endl;
    cout<<S.pop()<<endl;
    cout<<S.pop()<<endl;

    S.printStack();

}