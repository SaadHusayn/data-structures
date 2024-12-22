#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define int long long int

//we'll do seperate chaining first

class HashNode{
    public:
    string key;
    int val;
    isOccupied;

    HashNode(string _key="", int _val=0){
        key = _key;
        val = _val;
        isOccupied = false;
    }
};

class HashTable{
    public:
    vector<vector<HashNode>> htable;
    int table_size;

    public:
    HashTable(int _table_size){
        table_size = _table_size;
        htable.resize(table_size);
    }

    int hash_function(string key){
        int hashCode = 0;
        for(int i=0;i<key.length();i++){
            hashCode += (key[i]*pow(10, i));
        }
        return hashCode;
    }

    void insert()
};

signed main(){

}