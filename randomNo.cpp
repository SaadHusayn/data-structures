#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    cout<<static_cast<unsigned int>(time(0))<<endl;
    srand(time(0));
    cout<<(rand() % 10)<<" "<<(rand() % 10)<<" "<<(rand() % 10)<<endl;
    // srand(39); 
    cout<<(rand() % 10)<<" "<<(rand() % 10)<<" "<<(rand() % 10)<<endl;
}