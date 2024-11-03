#include<iostream>
#include"Stack.h"
using namespace std;

bool isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
}

int precedence(char ch){
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}


string infixToPostfix(string infix){
    string postfix = "";
    Stack<char> st;

    for(int i=0;i<infix.length();i++){
        if(iswalnum(infix[i])) postfix.append(1, infix[i]);

        else if(isOperator(infix[i])){
            if(st.isEmpty() || (!st.isEmpty() && precedence(st.peek()) < precedence(infix[i]))) st.push(infix[i]);
            else{
                while(!st.isEmpty() && precedence(st.peek()) >= precedence(infix[i])){
                    postfix.append(1, st.peek());
                    st.pop();
                }

                st.push(infix[i]);

            }

        }
    }

    while(!st.isEmpty()){
        postfix.append(1, st.peek());
        st.pop();
    }

    return postfix;
}

int main(){
    cout<<infixToPostfix("ab+c");
}