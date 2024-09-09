#include<iostream>
using namespace std;

void numberIntoWords(int n, string words[]){
    if(n==0) return ;

    numberIntoWords(n/10, words);
    cout<<words[n%10 - 1]<<endl;
}

int main(){
    string words[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    numberIntoWords(1234, words);
}