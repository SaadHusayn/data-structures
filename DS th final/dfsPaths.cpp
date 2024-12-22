#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsPaths(int source, int current, vector<vector<int>> &AdjList, vector<int> &path, vector<bool> &visited) {
    // Mark the current node as visited and add it to the path
    visited[current] = true;
    path.push_back(current);

    // If current node is different from source, print the path
    // if (current != source) {
        cout << source << " to " << current << ": ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << "-";
        }
        cout << endl;
    // }

    // Explore all unvisited neighbors
    for (int neighbor : AdjList[current]) {
        if (!visited[neighbor]) {
            dfsPaths(source, neighbor, AdjList, path, visited);
        }
    }

    // Backtrack: remove the current node from the path and mark it unvisited
    path.pop_back();
}

void printAllPaths(int source, vector<vector<int>> &AdjList) {
    int n = AdjList.size();
    vector<bool> visited(n, false);
    vector<int> path;

    dfsPaths(source, source, AdjList, path, visited);
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> AdjList = {
        {2},         // Node 0 is connected to node 2
        {2},         // Node 1 is connected to node 2
        {0, 1, 3},   // Node 2 is connected to nodes 0, 1, and 3
        {2, 4, 5},   // Node 3 is connected to nodes 2, 4, and 5
        {3},         // Node 4 is connected to node 3
        {3}          // Node 5 is connected to node 3
    };

    // Print all paths from source vertex 0
    printAllPaths(0, AdjList);

    return 0;
}
