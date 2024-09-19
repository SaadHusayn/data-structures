#include<iostream>
using namespace std;

int CountOnes(int n){
    if(n==0 || n==1) return n;

    return n%2 + CountOnes(n/2);
}

int main(){
    cout<<CountOnes(64);
}