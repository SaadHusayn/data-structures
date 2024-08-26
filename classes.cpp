#include<iostream>
#include<cstring>

using namespace std;

class MyClass{
    public:
    void func(string name) const{
        cout<<"Inside func function of myClass with name: "<<name<<endl;
    }
};

int main(){
    string your_name;

    MyClass myObj;
    cout<<"Enter your name: "<<endl;
    getline(cin, your_name);

    cout<<endl;
    myObj.func(your_name);
}