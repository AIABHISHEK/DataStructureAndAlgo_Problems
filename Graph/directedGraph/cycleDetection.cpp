#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// cycle detectio in the directed graph

void bfs(vector<int> graph[], int nodes, int i, vector<int> &visited){
    vector<int> inPath(nodes + 1, 0);
    inPath[i] = 1;
    visited[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (int j = 0; j < graph[node].size(); j++){
            if (!visited[graph[node][j]]){
                
            }
        }
    }
}

bool solve(vector<int> graph[], int nodes){

    vector<int> visited(nodes + 1, 0);
    for (int i = 1; i < nodes; i++){
        if(!visited[i]){
            bfs(graph, nodes, i, visited);
        }
    }
    return false;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

return 0;
}