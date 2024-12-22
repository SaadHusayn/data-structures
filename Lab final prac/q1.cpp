#include<iostream>
using namespace std;

struct data{
    string word;
    int freq;
};

class HashTable{
    public:
    int curr;
    data *htable;
    int table_size;

    HashTable(int _table_size){
        table_size = _table_size;
        htable = new data[table_size];
        for(int i=0;i<table_size;i++){
            htable[i].word ="";
            htable[i].freq = 0;
        }
        curr=0;
    }

    int hashfunction1(string key){
        int ans = 0;
        for(int i=0;i<key.length();i++){
            ans += (int)(key[i]);
        }
        return ans;
    }

    void printTable(){
        for(int i =0;i<table_size;i++){
            cout<<htable[i].word<<" "<<htable[i].freq<<endl;
        }
    }

    int hashfunction2(string key){
        int ans = 0;
        for(int i=0;i<key.length();i++){
            ans += (int)(key[i]);
        }
        ans = (ans % table_size);
        return ans;
    }

    void rehash(){
        data *temp = new data[2*table_size];
        for(int i=0;i<table_size*2;i++){
            temp[i].word = "";
            temp[i].freq = 0;
        }
        for(int i=0;i<table_size;i++){
            int hashIndex = hashfunction1(htable[i].word);
            for(int j=0;j<2*table_size;j++){
                int index = (hashIndex + j)%(table_size*2);
                if(temp[index].word == ""){
                    temp[index].word = htable[i].word;
                    temp[index].freq = htable[i].freq;
                    break;
                }else if(temp[index].word == htable[i].word){
                    ++ temp[index].freq;
                    break;
                }
            }
        }

        table_size*=2;
        delete htable;
        htable = temp;
    }

    void merge(data *arr, int s, int mid, int e){
        int n1 = mid - s + 1;
        int n2 = e - mid;

        data *a1 = new data[n1];
        data *a2 = new data[n2];

        for(int i=0;i<n1;i++){
            a1[i] = arr[s+i];
        }

        for(int i=0;i<n2;i++){
            a2[i] = arr[mid + i + 1];
        }

        int i = 0;
        int j = 0;
        int k = s;
        while(i<n1 && j<n2){
            if(a1[i].freq > a2[j].freq){
                arr[k++] = a1[i++];
            }else if(a1[i].freq == a2[j].freq){
                if(a1[i].word>a2[j].word){
                    arr[k++] = a1[i++];
                }else{
                    arr[k++] = a2[j++];
                }
            }else{
                arr[k++] = a2[j++];
            }
        }

        while(i<n1){
            arr[k++] = a1[i++];    
        }

        while(j<n2){
            arr[k++] = a2[j++];    
        }


    }

    void mergeSort(data *arr, int s, int e){
        if(s>=e) return;

        auto mid = s + (e-s)/2;

        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);

        merge(arr, s, mid, e);
    }


    void insert(string key){
        int hashIndex = hashfunction1(key);
        for(int i=0;i<table_size;i++){
            int index = (hashIndex + i*hashfunction2(key))%table_size;
            if(htable[index].word == ""){
                htable[index].word = key;
                htable[index].freq = 1;
                curr ++;
                return;
            }else if(htable[index].word == key){
                ++ htable[index].freq;
                return;
            }
        }

        //not able to insert, means table is full 
        rehash();
        insert(key);
    }

    void sortInDescending(){
        data *tmp = new data[curr];
        int j=0;
        for(int i=0;i<table_size;i++){
            if(htable[i].word != ""){
                tmp[j++] = htable[i];
            }
        }

        cout<<endl;

        for(int i=0;i<curr;i++){
            cout<<tmp[i].word<<" "<<tmp[i].freq<<endl;
        }

        mergeSort(tmp, 0, curr-1);

        cout<<endl;

        for(int i=0;i<curr;i++){
            cout<<tmp[i].word<<" "<<tmp[i].freq<<endl;
        }
    }
};


int main(){
    
    HashTable ht(3);
    ht.printTable();

    cout<<endl;

    ht.insert("saad");
    ht.insert("saad");
    ht.insert("saad");
    ht.insert("farhan");
    ht.insert("farhan");
    ht.insert("farhan");
    ht.insert("asfand");
    ht.insert("babar");
    ht.insert("babar");
    ht.insert("banno");
    ht.insert("banno");


    cout<<ht.curr<<endl;
    ht.printTable();

    ht.sortInDescending();
}