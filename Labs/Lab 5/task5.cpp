#include<iostream>
using namespace std;

bool isSafe(int x, int y, int **arr, int n, int **solution){
    return (x>=0 && x<n && y>=0 && y<n && arr[x][y] && !solution[x][y]);
}

bool lionInMaze(int x, int y, int **arr, int n, int **solution){
    //if lion is reached destination
    if(x==n-1 && y==n-1 && arr[x][y]){
        solution[x][y] = 1;
        return true;
    }

    if(isSafe(x, y, arr, n, solution)){
        solution[x][y] = 1;

        if(lionInMaze(x+1, y, arr, n, solution)){
            return true;
        }

        if(lionInMaze(x, y+1, arr, n, solution)){
            return true;
        }

        if(lionInMaze(x-1, y, arr, n, solution)){
            return true;
        }

        if(lionInMaze(x, y-1, arr, n, solution)){
            return true;
        }

        solution[x][y] = false;
        return false;
    }
    else return false;

}

int main(){
    int n = 5;

    int **arr = new int*[n];
    int **solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n]{0};
    }
    arr[0] = new int[5]{1, 0, 1, 0, 1};
    arr[1] = new int[5]{1, 1, 1, 1, 1};
    arr[2] = new int[5]{0, 1, 0, 1, 1};
    arr[3] = new int[5]{1, 0, 0, 1, 1};
    arr[4] = new int[5]{1, 1, 1, 0, 1};

    bool ans = lionInMaze(0, 0, arr, n, solution);

    if(ans) cout<<"Lion can have the meat"<<endl;
    else cout<<"Lion cannot have the meat"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }

}