#include<iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[],  int n, int dimIndex){
    if(dimIndex>=n) return 0;

    int size = sizes[dimIndex];
    int sum = 0;
    for(int i=0;i<size;i++){
        sum+=arr[dimIndex][i];
    }
    return sum + recursiveArraySum(arr, sizes, n, ++dimIndex);
}

int main(){
    int sizes[] = {1, 2, 3, 4};

    int **arr = new int*[4];

    for(int i=0;i<4;i++){
        arr[i] = new int[sizes[i]];
        for(int j=0;j<sizes[i];j++){
            arr[i][j] = j+1;
        }
    }

    cout<<"The array is given by:"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<sizes[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The sum of the array is "<<recursiveArraySum(arr, sizes, 4, 0);
}