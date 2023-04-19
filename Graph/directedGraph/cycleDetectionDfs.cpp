#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

bool dfs(vector<int> graph[], vector<int> &inPath, int i, vector<int> &visited){
    visited[i] = 1;
    // vector<int> inPath(nodes + 1, 0);
    inPath[i] = 1;
    for (int j = 0; j < graph[i].size(); j++){
        if(!visited[graph[i][j]]){
            if(dfs(graph, inPath, graph[i][j], visited)){
                return true;
            }
        }
        if (visited[graph[i][j]] == 1 && inPath[graph[i][j]] == 1){
            return true;
        }
    }
    inPath[i] = 0;
    return false;
}

bool solve(vector<int> graph[], int nodes){
    vector<int> visited(nodes + 1, 0);
    vector<int> inPath(nodes + 1, 0);
    for (int i = 1; i <= nodes; i++){
        if(dfs(graph, inPath, i, visited)){
            return true;
        }
    }
    return false;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int v, e;
cin >> v >> e;
vector<int> graph[v + 1]; // graph start from index 1
for (int i = 0; i < e; i++){
    int a, b;
    cin >> a >> b;   /// a ---> b
    graph[a].push_back(b);
}
cout<<solve(graph, v);
return 0;
}