#include<iostream>
using namespace std;

bool isSafeToPlace(int **board, int row, int col){
    
}

bool nQueens(int **board, int n, int row){
    if(row == n){
        //all queens have placed
        return true;
    }

    for(int col=0;col<n;col++){
        //queen ko rakhdo idher
        board[row][col] = 1;
        if(isSafeToPlace(board, row, col)){
            //agay wali row ma rakhna chaalo karo
            if(nQueens(board, n, row+1)){
                //solution mil gya 
                return true;
            }
        }
            //hatao is ko agar safe nhi h aur h tu solution nhi mila agar
            board[row][col] = 0;
        

    }
    //vai kahin bhi nhi rakh sakte 
    return false;
}

int main(){
    int n=5;

    //board is unoccupied
    int **board = new int *[n];
    for(int i=0;i<n;i++) board[i] = new int[n]{0};

    nQueens(board, n, 0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j])cout<<"Q";
            else cout<<".";
        }cout<<endl;
    }
}