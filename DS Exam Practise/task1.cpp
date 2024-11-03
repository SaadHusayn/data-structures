#include<iostream>
#include"LL.h"
using namespace std;

void print(Node *n){
    if(n==nullptr){
        cout<<endl;
        return;
    };

    cout<<n->data<<" ";
    print(n->next);

}


Node * oddThenEven(Node *n){
    Node *tmp = new Node();
    auto ptr = tmp;
    for(auto curr=n;curr!=nullptr;curr=curr->next){
        if(curr->data % 2 == 0){
            ptr->next = new Node(curr->data);
            ptr = ptr->next;
        }
    }
print(tmp);
    for(auto curr=n;curr!=nullptr;curr=curr->next){
        if(curr->data % 2){
            ptr->next = new Node(curr->data);
            ptr = ptr->next;
        }
    }

    print(tmp->next);

    return tmp->next;

}


int main(){
    // Node *n = new Node{17, new Node{15, new Node{8, new Node{12, new Node{10, new Node{5, new Node{4, new Node{1, new Node{7, new Node{6, nullptr}}}}}}}}}};

    // print(n);

    // n = oddThenEven(n);

    string s = "3";
    cout<<('3' == "3")<<endl;

}