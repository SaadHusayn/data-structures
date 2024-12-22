#include <iostream>
using namespace std;

class HashNode
{
public:
    HashNode *next;
    int val;

    HashNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class HashMap
{
private:
    HashNode **htable;
    static const int Table_size = 7;

public:
    HashMap()
    {
        htable = new HashNode *[Table_size];
        for (int i = 0; i < Table_size; i++)
        {
            htable[i] = nullptr;
        }
    }

    void HashInsert(int key)
    {
        int index = key % Table_size;
        HashNode *newNode = new HashNode(key);
        if (htable[index] == nullptr)
        {
            htable[index] = newNode;
        }
        else
        {
            HashNode *temp = htable[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print()
    {
        for (int i = 0; i < Table_size; i++)
        {
            HashNode *star = htable[i];
            while (star != nullptr)
            {
                cout << star->val << " ";
                star = star->next;
            }
            cout << endl;
        }
    }

    void HashDelete(int key){
        int index = key% Table_size;
        HashNode* temp = htable[index];
        if(temp == nullptr){
            return;
        }
        else if(temp->next == nullptr){
            if(temp->val == key){
                delete temp;
                htable[index] = nullptr;
            }
            return;
        }

        while(temp->next != nullptr && temp->next->val != key ){
            temp = temp->next;
        }
        if(temp->next == nullptr){
            return;
        }
        else{
            HashNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }

    }

    bool HashFind(int key){
        int index = key % Table_size;
        HashNode* temp = htable[index];
    if(temp == nullptr){
        return false;
    }
    else if(temp != nullptr){
        while(temp != nullptr && temp->val != key){
            temp = temp->next;
        }
        if(temp == nullptr){
            return false;
        }
        else{
            return true;
        }
    }
    }
};

int main()
{
    HashMap map;
    map.HashInsert(10);
    map.HashInsert(20);
    map.HashInsert(135);
    map.HashInsert(111);
    map.HashInsert(117);
    map.HashInsert(7);
    map.HashInsert(1);
    map.HashInsert(11);
    map.HashInsert(18);
    map.HashInsert(21);
    map.print();

    (map.HashFind(7)) ? (cout << "found") : (cout << "notfound");
    cout << endl;
    (map.HashFind(11))? (cout << "found") : (cout << "notFound");
    cout << endl;


    map.HashDelete(111);
    map.HashDelete(20);
    map.HashDelete(21);
    cout << endl;

    map.print();
    (map.HashFind(117)) ? (cout << "found") : (cout << "notfound");
    cout<<endl;

    map.HashDelete(117);
    (map.HashFind(117)) ? (cout << "found") : (cout << "notfound");
    map.print();
}
