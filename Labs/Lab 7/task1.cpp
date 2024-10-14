#include<iostream>
using namespace std;

class Product{
    public:
    string name;
    int price;

    Product(string _name, int _price):name(_name), price(_price){}
    
};



int partition(Product Products[], int s, int e){
    auto pivot = Products[s];
    auto cnt = 0;

    for(int i=s+1;i<=e;i++){
        if(Products[i].price < pivot.price || (Products[i].price == pivot.price && Products[i].name[0] < pivot.name[0])) cnt++;
    }

    auto pivotIndex = s + cnt;
    swap(Products[s], Products[pivotIndex]);

    int i=s, j=e;

    while(i<pivotIndex && j>pivotIndex){
        while(Products[i].price < pivot.price || (Products[i].price == pivot.price && Products[i].name[0] < pivot.name[0])){
            i++;
        }

        while(Products[j].price > pivot.price || (Products[j].price == pivot.price && Products[j].name[0] > pivot.name[0])){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(Products[i++], Products[j--]);
        }
    }

    return pivotIndex;

}

void sortByPrice(Product Products[], int s, int e){
    if(s>=e) return;

    int p = partition(Products, s, e);

    sortByPrice(Products, s, p-1);
    sortByPrice(Products, p+1, e);
}



int main(){

    Product Products[5]  = {Product("Laptop", 1000), Product("LED", 300), Product("Phone", 700), Product("Tablet", 600), Product("Monitor", 300)};

    for(int i=0;i<5;i++){
        cout<<Products[i].name<<" "<<Products[i].price<<endl;
    }
    cout<<endl;
    cout<<endl;
    sortByPrice(Products, 0, 4);

    for(int i=0;i<5;i++){
        cout<<Products[i].name<<" "<<Products[i].price<<endl;
    }

}