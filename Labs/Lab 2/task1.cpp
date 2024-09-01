#include<iostream>
using namespace std;

int main(){
    
    int inputArr1[5]; // for taking input first five numbers from the user
    int inputArr2[5]; // for taking input first five numbers from the user


    cout<<"Enter 5 elements: ";
    for(int i=0;i<5;i++){
        cin>>inputArr1[i];
    }

    //initialize jagged Array
    int **jaggedArray = new int*[5];
    for(int i=0;i<5;i++){
        jaggedArray[i] = new int[5];

        //inserting numbers in each row
        for(int j=0;j<5;j++){
            jaggedArray[i][j] = inputArr1[j];
        }
    }

    cout<<"\nThe Jagged Array is :"<<endl;

    //displaying jagged Array
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<jaggedArray[i][j]<<" ";
        }
        cout<<endl;
    }

    // taking input 5 more elements 
    cout<<"\nEnter 5 more elements: ";
    for(int i=0;i<5;i++){
        cin>>inputArr2[i];
    }

    //extending jagged Array and inserting numbers
    for(int i=0;i<5;i++){
        jaggedArray[i] = new int[10];
        for(int j=0;j<5;j++){
            jaggedArray[i][j] = inputArr1[j];
        }
        for(int j=5;j<10;j++){
            jaggedArray[i][j] = inputArr2[j-5];
        }
    }

    cout<<"\nThe Jagged Array after extension is :"<<endl;

    //displaying jagged Array
    for(int i=0;i<5;i++){
        for(int j=0;j<10;j++){
            cout<<jaggedArray[i][j]<<" ";
        }
        cout<<endl;
    }
}