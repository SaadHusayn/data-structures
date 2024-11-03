#include<iostream>
#include"LL.h"
using namespace std;

class CLL{
    public:
    Node *head;
    Node *tail;

    CLL(){head=nullptr;tail=nullptr;}

    void add(int val){
        if(head == nullptr && tail ==nullptr){
            head = new Node(val);
            tail = head;
            head->next = tail;
            
        }else{
            tail->next = new Node(val);
            tail->next->next = head;
            tail = tail->next;
        }
    }

    void display(){
        if(head == nullptr && tail == nullptr) return;

        

        for(auto curr = head;curr->next!=head;curr=curr->next){
            cout<<curr->data<<" ";
        }cout<<tail->data<<endl;
    }
};

int main(){
    CLL l1;

    l1.display();


    l1.add(1);

    l1.display();

    l1.add(2);
    l1.add(23);

    l1.display();
}