#include<iostream>
using namespace std;

int getCorrected(int n){
    int correctedNum = 0;
    int multiplier = 1;

    while(n>0){
        int lastDigit = n%10;
        int secondLastDigit = (n%100)/10;

        if(lastDigit==0 && secondLastDigit==9){
            //do nothing
        }else{
            correctedNum+= lastDigit*multiplier;
            multiplier*=10;
        }

        n/=10;
    }        

    return correctedNum;          
}

int main(){
    cout<<getCorrected(1540090);
}