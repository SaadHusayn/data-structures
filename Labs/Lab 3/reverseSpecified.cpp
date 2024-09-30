#include<iostream>
#include"SLL.h"
using namespace std;

Node * reverse(Node *n, Node *end){
    if(n==end || n->next == end) return n;

    auto remainingList = reverse(n->next, end);
    n->next->next = n;
    n->next = 0;

    return remainingList;
}

void func(Node *n, int s, int e){
    Node *st, *after;
    auto i=1;
    for(auto curr=n; curr!=0;i++, curr=curr->next){
        if(i==s) st = curr;
        if(i==e){
            after = curr->next;
        }
    }
    cout<<st->val<<" "<<after->val<<endl;

    auto curr = n;
    for(; curr->next!=st;curr=curr->next);
  SLL::printNode(n);

    curr->next = reverse(st, after);

  SLL::printNode(n);


    for(; curr->next!=0;curr=curr->next);
    curr->next = after;
}

int main(){
  int s = 2;
  int e = 5;
  Node *n = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, new Node{6, new Node{7, nullptr}}}}}}};


  SLL::printNode(n);

  func(n, s, e);

  SLL::printNode(n);
  
}