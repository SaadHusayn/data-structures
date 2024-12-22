#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> getAdjList(vector<pair<int, int>> edges,int num_vertices){
    vector<vector<int>> v(num_vertices);
    for(int i=0;i<edges.size();i++){
        v[edges[i].first].push_back(edges[i].second);
        v[edges[i].second].push_back(edges[i].first);
    }
    return v;
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

void bfs(vector<vector<int>> adjList, int vertex, int num_vertices){

    vector<bool> visited(num_vertices, false);

    queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;
    
    while(!q.empty()){
        int topVertex = q.front();
        q.pop();
        cout<<topVertex<<" ";
        for(int i=0;i<adjList[topVertex].size();i++){
            if(!visited[adjList[topVertex][i]]) {
                q.push(adjList[topVertex][i]);
                visited[adjList[topVertex][i]] = 1;
                }
        }
    }
}

bool hasCycle(vector<vector<int>> adjList, int vertex, int num_vertices){
    bool ans = false;
    vector<bool> visited(num_vertices, false);
    vector<int> parent(num_vertices, -1);
    queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;

    while(!q.empty()){
        auto queueTop = q.front();
        q.pop();

        for(auto neighbour:adjList[queueTop]){
            if(!visited[neighbour]){
                parent[neighbour]= queueTop;
                q.push(neighbour);
                visited[neighbour] = true;
            }else{
                if((neighbour != parent[queueTop]) ) {
                    return true;
                }
            }
        }
    }
    return false;

}

int main(){
    vector<pair<int, int>> edges = {{0,1}, {1,2}, {3,4}, {2,3}, {5,0}};
    int num_vertices = 6;

    vector<vector<int>> v = getAdjList(edges, num_vertices);
    displayAdjacencyList(v);
    cout<<endl;

    bfs(v, 0, num_vertices);

    cout<<endl;

    cout<<hasCycle(v, 0, num_vertices);
}