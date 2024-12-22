#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* Next;

    Node(int data){
        val = data;
        Next = nullptr;
    }
};

class Hash{
    public:
    Node **hashTable;
    int tableSize = 10;

    Hash(){
        hashTable = new Node*[tableSize];
        for(int i=0; i< tableSize; i++){
            hashTable[i] = nullptr;
        }
    }

    int hashFunction(int val){
        return (val%tableSize);
    }

    void hashInsert(int val){
        int index = hashFunction(val);
        Node*  newNode = new Node(val);
            if(hashTable[index] == nullptr){
                hashTable[index] = newNode;
            }
            else{
                Node* temp = hashTable[index];
                while(temp != nullptr){
                    temp = temp->Next;
                }
                temp->Next = newNode;
            }
    }

    void print(){
        for(int i =0; i< tableSize; i++){
            Node *temp = hashTable[i];
            while(temp != nullptr){
                cout << temp->val << " ";
                temp = temp->Next;
            }
        cout << endl;
        }
    }

    void ToDelete(int key){
        int index = hashFunction(key);
        Node* temp = hashTable[index];
        if(temp == nullptr){
            return;
        }
        else if(temp->Next == nullptr){
            if(temp->val == key){
            delete temp;
            hashTable[index] = nullptr;
            }
            return;
        }

        while(temp->Next != nullptr && temp->val != key){
            temp = temp->Next;
        }

        if(temp == nullptr){
            return;
        }
        else{
            Node* toDelete = temp;
            temp->Next = temp->Next->Next;
            delete toDelete;
            return; 
        }
    }
};

int main(){
    Hash h1;
    h1.hashInsert(32);
    h1.hashInsert(23);
    h1.hashInsert(20);
    h1.hashInsert(10);
    h1.hashInsert(62);
    h1.hashInsert(49);

    h1.print();
    h1.ToDelete(23);
    h1.ToDelete(32);
    h1.ToDelete(10);
    h1.print();


}