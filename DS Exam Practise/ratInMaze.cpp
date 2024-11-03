#include<iostream>
using namespace std;

bool isSafe(int x, int y, int n, int **maze, int **solution){
    
    return (x>=0 && x<n && y>=0 && y<n && maze[x][y] && !solution[x][y]);
}

bool ratInMaze(int x, int y, int n, int **maze, int **solution){
    //base condition
    if(x==n-1 && y==n-1 && maze[x][y] && !solution[x][y]){
        solution[x][y] = 1;
        return true;
    }

    if(isSafe(x, y, n, maze, solution)){
        solution[x][y] = 1;

        // Move right
        if (ratInMaze(x, y + 1, n, maze, solution)) return true;

        // Move down
        if (ratInMaze(x + 1, y, n, maze, solution)) return true;

        // Move left
        if (ratInMaze(x, y - 1, n, maze, solution)) return true;

        // Move up
        if (ratInMaze(x - 1, y, n, maze, solution)) return true;

        //nahi mila solution
        solution[x][y] = 0;
        return false;
    }return false;
}

int main(){
    int n = 5;
    int **maze = new int *[n];
    maze[0] = new int[n]{1, 1, 1, 1, 1};
    maze[1] = new int[n]{0, 0, 0, 1, 0};
    maze[2] = new int[n]{1, 1, 1, 1, 0};
    maze[3] = new int[n]{1, 0, 1, 0, 1};
    maze[4] = new int[n]{1, 1, 1, 1, 1};

    int **solution = new int *[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n]{0};
    }

    if(ratInMaze(0, 0, n, maze, solution)){
        cout<<"Path found"<<endl;
    }else{
        cout<<"Path not found"<<endl;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }cout<<endl;
    }

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] maze[i];
        delete[] solution[i];
    }
    delete[] maze;
    delete[] solution;

}   