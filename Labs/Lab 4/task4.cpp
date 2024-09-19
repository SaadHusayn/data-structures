#include <iostream>
using namespace std;

void mySwap(float &a, float &b){
    auto temp = a;
    a = b;
    b = temp;
}

void printWeights(float *weights, int size){
    cout << endl;
    for(auto i=0;i<size;i++){
        cout<<weights[i]<<" ";
    }
    cout<<endl;
}

void sortWeights(float *weights, int size){

    //sorting using shell sort with custom gap
    int h=1;
    while(h < size/3) h = 3*h + 1;

    while(h >= 1){
        for(auto i=h;i<size;i++){
            for(auto j=i;j>=h && (weights[j] < weights[j-h]);j-=h){
                mySwap(weights[j], weights[j-h]);
            }
        }
        h = h/3;
    }
}

int main()
{
    float weights[9] = { 67.69, 72.89, 71.17, 63.95, 81.83, 81.29, 65.98, 78.20, 75.57 };

    printWeights(weights, 9);

    sortWeights(weights, 9);

    printWeights(weights, 9);
}