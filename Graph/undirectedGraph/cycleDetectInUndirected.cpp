#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// cycle detection in the undirected graph

bool bfs(int i ,vector<int> graph[], vector<int>visited){
    queue<pair<int, int>> q;
    q.push({i, 0});
    while (q.size())
    {
        pair<int,int> p = q.front();
        int node = p.first;
        int parent = p.second;
        q.pop();
        visited[node] = true;
        for (int j = 0; j < graph[node].size(); j++)
        {
            int l = graph[node][j];
            if (!visited[l]){
                visited[l] = true;
                q.push({l, node});
            }
            else if(visited[l] && l != parent){
                return true;
            }
        }
    }
    return false;
}

bool cycleDectection(vector<int> graph [], int nodes){
    vector<int> visited(nodes + 1, 0);
    visited[1] = 0;
    return bfs(1, graph, visited);
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
// int t;
// cin >> t;
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
bool t = cycleDectection(graph, v);

cout << t;
return 0;
}