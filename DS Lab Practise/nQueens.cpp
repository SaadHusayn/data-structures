#include<iostream>
#include<ctime>
using namespace std;

bool isSafeToPlace(int **board, int row, int col, int n){
    for(int i=0;i<n;i++){
        if(board[row][i]) return false;
    }
    for(int i=0;i<=row;i++){
        if(board[i][col]) return false;
    }

    //diagonals ma check maarlo
    int i=row;
    int j=col;

    while(i>=0 && j>=0){
        if(board[i--][j--]) return false;
    }

    i=row;
    j=col;

    while(i>=0 && j<n){
        if(board[i--][j++]) return false;
    }

    return true;
}

bool nQueens(int **board, int n, int row){
    if(row == n){
        //all queens have placed
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafeToPlace(board, row, col, n)){
            board[row][col] = 1;
            //agay wali row ma rakhna chaalo karo
            if(nQueens(board, n, row+1)){
                //solution mil gya 
                return true;
            }
        }
            //hatao is ko agar tu solution nhi mila agar
            board[row][col] = 0;
        

    }
    //vai kahin bhi nhi rakh sakte 
    return false;
}

int main(){
    int n=22;

    auto before = clock();

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

    auto duration= clock() - before;
    cout << "Duration: " << (float)duration / CLOCKS_PER_SEC << " seconds";


}