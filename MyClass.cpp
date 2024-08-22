#include<iostream>
#include "MyClass.h"
using namespace std;


MyClass::MyClass(int v):var(v){

}

void MyClass::setVar(int newVar){
    var = newVar;
}

int MyClass::getVar() const{
    return var;
}

void MyClass::display() const{
    cout<<getVar()<<endl;
}