#include <iostream>
#include <vector>
using namespace std;

// DFS using recursion
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " "; // Print the node (or handle it as needed)
    
    // Recur for all neighbors
    for (int i = 0; i < adj.size(); ++i) {
        if (adj[node][i] == 1 && !visited[i]) { // If there's an edge and the neighbor is not visited
            dfs(i, adj, visited);
        }
    }
}

int main() {
    // Example graph using adjacency matrix
    // 0 represents no edge, 1 represents an edge
    int n = 6; // Number of nodes
    vector<vector<int>> adj(n, vector<int>(n, 0)); // Initialize adjacency matrix with 0

    // Create edges
    adj[0][1] = adj[1][0] = 1; // Edge between 0 and 1
    adj[0][2] = adj[2][0] = 1; // Edge between 0 and 2
    adj[1][3] = adj[3][1] = 1; // Edge between 1 and 3
    adj[1][4] = adj[4][1] = 1; // Edge between 1 and 4
    adj[2][5] = adj[5][2] = 1; // Edge between 2 and 5
    adj[4][5] = adj[5][4] = 1; // Edge between 4 and 5

    vector<bool> visited(n, false); // visited array to track visited nodes
    cout << "DFS starting from node 0: ";
    dfs(0, adj, visited); // Start DFS from node 0
    cout << endl;

    return 0;
}
