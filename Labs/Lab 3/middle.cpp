#include<iostream>
#include"SLL.h" 
using namespace std;


int main(){

    Node *n = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, new Node{6, nullptr}}}}}};
}