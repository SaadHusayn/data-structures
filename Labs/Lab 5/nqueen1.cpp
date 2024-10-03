#include<iostream>
using namespace std;

void printBoard(int **board, int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]) cout<<"Q";
            else cout<<".";
        }
        cout<<endl;
    }
}

bool isSafe(int **board, int n, int row, int col){
    //checking for row and column
    for(int i=0;i<row;i++){
        if(board[row][i] || board[i][col]) return false;
    }

    //now checking for left diagonal
    int i=row;
    int j=col;
    while(i>=0 && j>=0){
        if(board[i--][j--])return false;
    }

    //now checking for right diagonal
    i=row;
    j=col;
    while(i>=0 && j<n){
        if(board[i--][j++])return false;
    }

    return true;
}

bool solveNQueens(int **board, int n, int row=0){
    if(row==n){
        //queens are placed in every row
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(board, n, row, col)){
            board[row][col] = 1; //place the queen there  
            if(solveNQueens(board, n, row+1)){ //next row ma rakhne lag jao
                printBoard(board, n);
            }
            //solution nhi mila queen rakh kar
            board[row][col] = 0; //hata do
        }
    }

    //kahin bhi nhi rakh sakte tu false return krke backtrack krjao
    return false;
}



int main(){
    int n;
    cin>>n;
    int **board = new int *[n];
    for(int i=0;i<n;i++){
        board[i] = new int[n];
        for(int j=0;j<n;j++){
            board[i][j] = 0;
        }
    }
    solveNQueens(board, n);


}