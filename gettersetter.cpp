#include<iostream>
using namespace std;

class MyClass{
    int s;
    public:

    int getS() const{
        return MyClass::s;
    }
    void setS(int newS){
        s = newS;
    }
    void func(string name) const{
        cout<<"Inside func function of myClass with name: "<<name<<endl;
    }
};

int main(){

    string your_name;

    MyClass myObj;
    cout<<myObj.getS()<<endl;
    myObj.setS(33);
    cout<<myObj.getS()<<endl;

    // cout<<"Enter your name: "<<endl;
    // getline(cin, your_name);

    // cout<<endl;
    // myObj.func(your_name);
}