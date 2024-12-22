#include<iostream>
using namespace std;
void printArray(int arr[], int s, int e){
    cout<<endl;
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int partition(int arr[], int s, int e){
    int pivot = arr[e]; //first element

    int cnt = 0; // no of elements less than pivot

    for(int i=s;i<e;i++){
        if(arr[i]<pivot) cnt++;
    }

    int pivotIndex = s + cnt;
    swap(arr[e], arr[s + cnt]);

    //left aur right part pr sahi sahi element daal lete hn

    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot) i++; //koi bara milega tu swap krenge 

        while(arr[j]>=pivot) j--;

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e){
    if(s >= e) return ;

    auto p = partition(arr, s, e); // this will return the index of the pivot correctly placed in the array

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);

}



int main(){
    int arr[9] = {3, 1, 2, 4, 1, 5, 2, 6, 4};

    quickSort(arr, 0, 8);

    printArray(arr, 0, 8);
}