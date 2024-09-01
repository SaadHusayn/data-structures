#include<iostream>
#include<cassert>
#include "matrix_multiply.h"

using namespace std;

int main(){
    int m, n, x, y;
    
    cout<<"\nEnter order for the first matrix: ";
    cin>>m>>n;

    cout<<"\nEnter order for the second matrix: ";
    cin>>x>>y;

    assert((void("matricies can be multiplied?"), n==x));

    cout<<"Enter first matrix: "<<endl;
    int **matrix1 = new int*[m];
    for(int i=0;i<m;i++){
        matrix1[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>matrix1[i][j];
        }
    }

    cout<<"Enter second matrix: "<<endl;
    int **matrix2 = new int*[x];
    for(int i=0;i<x;i++){
        matrix2[i] = new int[y];
        for(int j=0;j<y;j++){
            cin>>matrix2[i][j];
        }
    }

    int **resultantMatrix = matrixMultiply(matrix1, m, n, matrix2, x, y);

    cout<<"\nThe multiplication resultant matrix is: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<y;j++){
            cout<<resultantMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}