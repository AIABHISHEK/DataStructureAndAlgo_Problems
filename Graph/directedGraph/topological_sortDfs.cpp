#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// topological sort

void dfs(vector<int> graph[], vector<int> &visited, stack<int> &s, int i){
    visited[i] = 1;

    for (int j = 0; j < graph[i].size(); j++){
        if(!visited[graph[i][j]]){
            dfs(graph, visited, s, graph[i][j]);
        }
    }
    s.push(i);
}

void solve(vector<int> graph[], int nodes)
{
    stack<int> s;
    vector<int> visited(nodes + 1, 0);
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, s, i);
        }
    }
    int n = nodes;
    while(n){
        int t = s.top();
        s.pop();
        cout << t<< " , ";
        n--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int v, e;
    cin >> v >> e;
    vector<int> graph[v + 1]; // graph start from index 1
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b; /// a ---> b
        graph[a].push_back(b);
    }
    solve(graph, v);

    return 0;
}