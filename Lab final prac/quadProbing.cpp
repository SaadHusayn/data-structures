#include<iostream>
using namespace std;

class HashMap{
    public:
    int *htable;
    int table_size;

    HashMap(int _table_size){
        table_size = _table_size;
        htable = new int[table_size];
        for(int i=0;i<table_size;i++){
            htable[i] = -1;
        }
    }

    int hashFunction(int val){
        return (val % table_size);
    }

    void insert(int val){
        
        int hashIndex = hashFunction(val);
        for(int i=0;i<table_size;i++){
            int index = (hashIndex + i*i)%table_size;
            if(htable[index] == -1 || htable[index] == -2){
                htable[index] = val;
                cout<<"Inserted"<<endl;
                return;
            }
        }

        cout<<"table is full"<<endl;

        
    }

    void printTable(){
        for(int i=0;i<table_size;i++){
            cout<<htable[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    HashMap hm(13);
    hm.printTable();

    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);

    hm.printTable();
}