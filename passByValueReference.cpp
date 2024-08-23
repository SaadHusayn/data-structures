#include<iostream>
using namespace std;

void squareByValue(int);
void squareByReference(int &);


int x=44;
int main(){
    int x = 4;
    squareByValue(x);
    cout<<x<<endl;
    x = 4;
    cout<<::x<<endl;
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