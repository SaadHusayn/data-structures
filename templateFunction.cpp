#include<iostream>
using namespace std;

template<typename T>
T add(T num1, T num2){
    return num1 + num2;
}

int main(){
    cout<<add(3,4)<<endl;
    cout<<add(4.3, 44.5)<<endl;
}