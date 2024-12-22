#include<iostream>
using namespace std;

class HashMap{
    public:
    int *htable;
    int table_size;
    int curr;
    float load_factor;

    HashMap(int _table_size){
        table_size = _table_size;
        htable = new int[table_size];
        for(int i=0;i<table_size;i++){
            htable[i] = -1;
        }
        curr = 0;
        load_factor = 0;
    }

    int hashFunction(int val){
        return (val % table_size);
    }

    void rehash(){
        cout<<"doing rehashing"<<endl;
        int *temp = new int[table_size*2];

        for(int i=0;i<table_size*2;i++) temp[i] = -1;

        for(int i=0;i<table_size;i++){
            if((htable[i] != -1) && (htable[i] != -2)){
                int hashedIndex = htable[i] % (table_size*2);
                for(int j=0;j<table_size*2;j++){
                    int index = (hashedIndex + j)%(table_size*2);
                    if(temp[index] == -1){
                        temp[index] = htable[i];
                        break;
                    }
                }
            }
        }

        delete htable;
        htable = temp;
        table_size*=2;
        load_factor = curr*1.0/table_size;

    }

    void insert(int val){
        
        int hashIndex = hashFunction(val);
        for(int i=0;i<table_size;i++){
            int index = (hashIndex + i)%table_size;
            if(htable[index] == -1){
                htable[index] = val;
                cout<<"Inserted"<<endl;
                curr ++;
                load_factor = curr*1.0/table_size;
                if(load_factor>=0.7) rehash();
                return;
            }
        }


        
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
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    hm.insert(4);
    
    hm.printTable();



}