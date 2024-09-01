#include<iostream>
#include<string>
using namespace std;

int main(){
    string *str = new string;
    *str = "Hello";
    cout<<*str<<" "<<sizeof(str)<<" "<<sizeof(*str);
}