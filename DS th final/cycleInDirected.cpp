#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> getAdjList(vector<pair<int, int>> edges,int num_vertices){
    vector<vector<int>> v(num_vertices);
    for(int i=0;i<edges.size();i++){
        v[edges[i].first].push_back(edges[i].second);
    }

    return v;
}

bool dfs(int vertex, vector<vector<int>> adjlist, vector<bool> &visited, vector<bool> &recStack){
    visited[vertex] = true;
    recStack[vertex] = true;

    for(auto neighbour: adjlist[vertex]){
        if(!visited[neighbour]){
            auto ans = dfs(neighbour, adjlist, visited, recStack);
            if(ans) return true;
        }else if(recStack[neighbour]){
            return true;
        }
    }

//not found cycle with this vertex
    recStack[vertex] = false;
    return false;
}

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

bool hasCycle(vector<vector<int>> adjlist){
    vector<bool> visited(adjlist.size(), false);
    vector<bool> recStack(adjlist.size(), false);

    for(int i=0;i<adjlist.size();i++){// traverse each node
        if(!visited[i]) {
            auto isThereACycle = dfs(i, adjlist, visited, recStack);
            if (isThereACycle) return true;
        }
    }

    return false;
}

int main(){
    int num_vertices = 5;
    vector<pair<int, int>> edges = {{0,1}, {1,2}, {2,3},{4, 0}, {2, 4}};

    vector<vector<int>> v = getAdjList(edges, num_vertices);

    displayAdjacencyList(v);
    cout<<endl;
    cout<<hasCycle(v)<<endl;
}