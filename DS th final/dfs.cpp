#include<iostream>
#include<vector>
using namespace std;

void displayAdjacencyList(vector<vector<int>> v){
        cout<<"\nAdjacency List is given by: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<i<<" -> ";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

}

void dfs(vector<vector<int>> Adjlist, int vertex, vector<bool> &visited, vector<int> &path){
    visited[vertex] = 1;
    path.push_back(vertex);

    cout<<path[0]<<" to "<<path[path.size() - 1]<<": ";
    for(auto i:path) cout<<i<<" ";
    cout<<endl;

    for(int i=0;i<Adjlist[vertex].size();i++){
        if(!visited[Adjlist[vertex][i]]) dfs(Adjlist, Adjlist[vertex][i], visited, path);
    }

    // cout << "\nVisited All the neighbours of "<<vertex<<endl;
    path.pop_back();
}


vector<vector<int>> getAdjList(vector<pair<int, int>> edges,int num_vertices){
    vector<vector<int>> v(num_vertices);
    for(int i=0;i<edges.size();i++){
        v[edges[i].first].push_back(edges[i].second);
        v[edges[i].second].push_back(edges[i].first);
    }

    return v;
}

vector<pair<int, int>> getEdgesList(vector<vector<int>> v){
    vector<pair<int, int>> edges;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] >= i) edges.push_back(make_pair(i, v[i][j]));
        }
    }

    return edges;
}

vector<vector<int>> getAdjMatrixFromAdjList(vector<vector<int>> adjList){
    int num_vertices = adjList.size();
    vector<vector<int>> matrix(num_vertices, vector<int>(num_vertices, 0));

    for(int i=0;i<num_vertices;i++){
        for(int j=0;j<adjList[i].size();j++){
            matrix[i][adjList[i][j]] = 1;
            matrix[adjList[i][j]][i] = 1;
        }
    }

    return matrix;
}

vector<vector<int>> getAdjListFromAdjMatrix(vector<vector<int>> matrix){
    int num_vertices = matrix.size();
    vector<vector<int>> AdjList(num_vertices);

    for(int i=0;i<num_vertices;i++){
        for(int j=0;j<num_vertices;j++){
            if(matrix[i][j]) AdjList[i].push_back(j);
        }
    }

    return AdjList;
}

bool hasCycle(int vertex, int parent, vector<vector<int>> AdjList, vector<int> &visited){
    visited[vertex] = 1;

    for(auto neighbour: AdjList[vertex]){
        if(!visited[neighbour]){
            bool aagayCycleHaiKya = hasCycle(neighbour, vertex, AdjList, visited);
            if(aagayCycleHaiKya) return true;
        }else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

int main(){
    int num_vertices = 6;
    vector<pair<int, int>> edges = {{0,1}, {1,2}, {3,4}, {2,3},{4, 5}, {5,0}};

    vector<vector<int>> v = getAdjList(edges, num_vertices);
    vector<int> visited(num_vertices, 0);
    cout<<hasCycle(0, -1, v, visited)<<endl;
}