// Implement and insert the values “BORROWROB” in the stack and identify if it’s palindrome
// or not. Use the push and pop functions to accomplish this (Note: Use Arrays to accomplish
// this)
#include<iostream>
#include"Stack.h"
using namespace std;


bool checkPalindrome(Stack<char> s, string str){
    for(int i=0;i<str.length();i++){
        if(s.pop() != str[i]) return false;
    }
    return true;
}

int main(){
    string str = "BORROWROB";
    Stack<char> s;

    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    
    if(checkPalindrome(s, str)) cout<<"It is a Palindrome"<<endl;
    else cout<<"It is not a palindrome";


}