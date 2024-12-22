#include<iostream>
#include<vector>
using namespace std;

    // Function to find the number of islands.
    void dfs(int i, int j, int n, int m, vector<vector<char>>&grid, vector<vector<int>> &visited){
        if(visited[i][j] || i<0 || i>=n || j<0 || j>=m || (grid[i][j]=='0')) return;
        
        visited[i][j] = 1;
        for(int a = -1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                int row = i + a;
                int col = j + b;
                if(row>=0 && row < n && col >=0 && col < m && (grid[row][col]=='1') && !visited[row][col]){
                    dfs(row, col, n, m, grid, visited);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code 
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((grid[i][j]=='1') && !visited[i][j]){
                    ans++;
                    dfs(i, j, n, m, grid, visited);
                }
            }
        }
        
        return ans;
    }

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m, '0'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    cout<<numIslands(grid)<<endl;
}