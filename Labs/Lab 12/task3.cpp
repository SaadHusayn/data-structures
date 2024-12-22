#include<vector>
#include<iostream>
#include<utility>
using namespace std;

vector<vector<int>> getAdjacencyList(vector<pair<int, int>> edges, int v){
    vector<vector<int>> list(v);
    
    for(int i=0;i<edges.size();i++){
        list[edges[i].first].push_back(edges[i].second);
        list[edges[i].second].push_back(edges[i].first);
    }

    return list;
}

int main(){
    int v, e;
    cin>>v>>e;
    vector<pair<int,int>> edges(e);
    for(int i=0;i<e;i++){
        cin>>edges[i].first>>edges[i].second;
    }

    vector<vector<int>> adjacencyList = getAdjacencyList(edges, v);
    cout<<endl;

    for(int i=0;i<adjacencyList.size();i++){
        for(int j=0;j<adjacencyList[i].size();j++){
            cout<<adjacencyList[i][j]<<" ";
        }
        cout<<endl;
    }
}