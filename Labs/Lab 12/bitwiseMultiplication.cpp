#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int b = 9;

    int ans = 0;
    for(int i=0;a>0;i++){
        int lastBit = a&1;
        if(lastBit){
            ans += (b<<i);
        }
        a>>=1;
    }

    cout<<ans<<endl;
}