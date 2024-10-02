#include<iostream>
using namespace std;



bool solveNQueens(int **board, int n, int row=0){
    if(row==n){
        //queens are placed in every row
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(board, n, row, col)){
            board[row][col] = 1; //place the queen there  
            if(solveNQueens(board, n, row+1)){ //next row ma rakhne lag jao
                return true;//solution milgya
            }
            //solution nhi mila queen rakh kar
            board[row][col] = 0; //hata do
        }
    }

    //kahin bhi nhi rakh sakte tu false return krke backtrack krjao
    return false;
}

int main(){
    int n=4;
    int **board = new int *[n];
    for(int i=0;i<n;i++){
        board[i] = new int[n];
        for(int j=0;j<n;j++){
            board[i][j] = 0;
        }
    }

    solveNQueens(board, n);


}