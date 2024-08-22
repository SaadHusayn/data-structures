#include<iostream>
using namespace std;

void squareByValue(int);
void squareByReference(int &);

int main(){
    int x = 4;
    squareByValue(x);
    cout<<x<<endl;
    x = 4;
    squareByReference(x);
    cout<<x<<endl;

}

void squareByValue(int copy){
    copy *= copy;
    cout<<"in square by value "<<copy<<endl;
}

void squareByReference(int &ref){
    ref *= ref;
    cout<<"in square by ref "<<ref<<endl;
}