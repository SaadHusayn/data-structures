#include<iostream>
using namespace std;

void printgrid(int **grid, int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]) cout<<"F";
            else cout<<".";
        }
        cout<<endl;
    }
}

bool isSafe(int **grid, int n, int row, int col){
    //checking for row and column
    for(int i=0;i<row;i++){
        if(grid[row][i] || grid[i][col]) return false;
    }

    //now checking for left diagonal
    int i=row;
    int j=col;
    while(i>=0 && j>=0){
        if(grid[i--][j--])return false;
    }

    //now checking for right diagonal
    i=row;
    j=col;
    while(i>=0 && j<n){
        if(grid[i--][j++])return false;
    }

    return true;
}

bool placeFlags(int **grid, int n, int row=0){
    if(row==n){
        // flags are placed in every row
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(grid, n, row, col)){
            grid[row][col] = 1; //place the flag there  
            if(placeFlags(grid, n, row+1)){ //next row ma rakhne lag jao
                return true;
            }
            //solution nhi mila flag rakh kar
            grid[row][col] = 0; //hata do
        }
    }

    //kahin bhi nhi rakh sakte tu false return krke backtrack krjao
    return false;
}



int main(){
    int n=4;
    int **grid = new int *[n];
    for(int i=0;i<n;i++){
        grid[i] = new int[n];
        for(int j=0;j<n;j++){
            grid[i][j] = 0;
        }
    }
    placeFlags(grid, n);

    cout<<"The grid after placing the flags is given by"<<endl;

    printgrid(grid, n);

}