#include<iostream>
using namespace std;

int main(){
    int j = 0;
    for(int i=j;i<=4;i++, j++){
        if(i==1){break;}
        cout<<i<<endl;
    }
    cout<<j<<endl;

    int i=0;
    // do{
    //     cout<<i++<<endl;
    // }while(i<=4);

    // while(i<=4){
    //     if(i==1){continue;}
    //     cout<<i++<<endl;
    // }
}

