#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void dfs(int i, vector<int> graph[], vector<int> &visited, vector<int> &dfs_seq){
    visited[i] = true;
    dfs_seq.push_back(i);
    for (int j = 0; j < graph[i].size(); j++){
        int node = graph[i][j];
        if(!visited[node]){
            dfs(node, graph, visited, dfs_seq);
        }
    }
}

vector<int> dfs_travel(vector<int> graph[], int node)
{

    vector<int> visited(node + 1, 0);
    vector<int> dfs_seq;
    // for (int i = 1; i <= node; i++)
    // {
        dfs(1, graph, visited, dfs_seq);
    // }
    return dfs_seq;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int v, e;
cin >> v >> e;
vector<int> graph[v + 1]; // graph start from index 1
for (int i = 0; i < e; i++)
{
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}
vector<int> bfs_seq = dfs_travel(graph, v);
for (auto i : bfs_seq)
{
    cout << i << " ";
}

return 0;
}