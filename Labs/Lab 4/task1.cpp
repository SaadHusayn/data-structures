// Implement the bubble sort algorithm to sort in descending order (starting from the initial pass).
// Take array[10]= {5,1,3,6,2,9,7,4,8,10}. You can also take your array as user input.

#include <iostream>
using namespace std;

void mySwap(int &a, int &b){
    if(a==b) return;

    a = a^b;
    b = a^b;
    a = a^b;
}


void print(int *arr, int n){
    for(auto i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void mySort(int *arr, int n){
    for(auto i=0;i<n-1;i++){
        for(auto j=0;j<n-i-1;j++){
            if(arr[j+1]>arr[j]) mySwap(arr[j], arr[j+1]);
        }
    }
}

int main()
{
    int array[10] = {5, 1, 3, 6, 2, 9, 7, 4, 8, 10};

    print(array, 10);

    mySort(array, 10);

    print(array, 10);


}