#include<iostream>
using namespace std;

class HashNode{
    public:
    int val;
    HashNode *next;

    HashNode(int _val=0){
        val = _val;
        next = nullptr;
    }
};

class HashMap{
    public:
    HashNode **htable;//array of hashNodes
    int TABLE_SIZE;

    HashMap(int table_size){
        TABLE_SIZE = table_size;
        htable = new HashNode*[TABLE_SIZE];
        
    }
};