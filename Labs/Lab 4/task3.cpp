#include<iostream>
using namespace std;

string designations[6] = {"CEO", "CTO", "CFO", "VP", "MGR", "EMP"};

void mySwap(string &a, string &b){
    auto temp = a;
    a = b;
    b = temp;
}

int priority(string post){
    for(auto i=0;i<6;i++){
        if(designations[i] == post) return i;
    }

    return -1;
}

void printArrangement(string *arrangement, int n){
    cout<<endl;
    for(auto i=0;i<n;i++){
        cout<<arrangement[i]<<endl;
    }
}

void organizeArrangement(string *arr, int size){
    //sorting using insertion sort
    for(auto i=0;i<size;i++){
        for(auto j=i;j>0 && (priority(arr[j-1])) > priority(arr[j]);j--) mySwap(arr[j], arr[j-1]);
    }
}

int main(){

    string arrangement[8] = {"EMP", "CFO", "MGR", "EMP", "VP", "CTO", "MGR", "CEO"};

    printArrangement(arrangement, 8);

    organizeArrangement(arrangement, 8);

    printArrangement(arrangement, 8);

}