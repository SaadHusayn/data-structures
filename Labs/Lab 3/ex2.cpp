#include<iostream>
#include"SLL.h"
using namespace std;

Node *reverseList(Node *head){
    if(head==nullptr || head->next==nullptr) return head;

    auto remainingList = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return remainingList;
}

Node *getRightSideList(Node *head){
    auto singleStepper = head;
    auto doubleStepper = head;


    while(doubleStepper->next!=nullptr && doubleStepper->next->next!=nullptr){
        singleStepper = singleStepper->next;
        doubleStepper = doubleStepper->next->next;
    }

    return singleStepper->next;

}

bool isPalindrome(Node *n){

    if(n==nullptr || n->next==nullptr) return true;

    auto rightList = getRightSideList(n);
    auto reversedRightList = reverseList(rightList);


    auto i = n;
    auto j = reversedRightList;
    for(;j!=nullptr;i=i->next, j=j->next){
        if(i->val != j->val) return false;
    }

    return true;
}

int main(){
    Node *n = new Node{1, new Node{0, new Node{2, new Node{0, new Node{1, nullptr}}}}};

    if(isPalindrome(n)){
        cout<<"List is Palindrome";
    }else{
        cout<<"List is not Palindrome";
    }
}