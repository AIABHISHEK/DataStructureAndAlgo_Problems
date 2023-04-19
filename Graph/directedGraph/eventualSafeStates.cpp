#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// given a directed graph find all the safe nodes in ascending order
// a nodes is safe node if it satrting from the safe node its all path ends at at teminal node
// a node is terminal if it does not have outgoing edge

bool dfs(vector<int> graph[], int i, vector<int> &visited, set<int> &safeNode, vector<int> &inPath)
{
    visited[i] = 1;
    inPath[i] = 1;
    for (int j = 0; j < graph[i].size(); j++)
    {
        cout << graph[i][j];
        if (!visited[graph[i][j]])
        {
            if(dfs(graph, graph[i][j], visited, safeNode, inPath)){
                safeNode.insert(graph[i][j]);
            }
            else{
                return false;
            }
        }
        else if (visited[graph[i][j]] && inPath[graph[i][j]]){
            return false;
        }
    }
    safeNode.insert(i);
    inPath[i] = 0;
    return true;
}

void solve(vector<int> graph[], int nodes)
{
    vector<int> visited(nodes + 1, 0);
    set<int> safeNode;

    for (int i = 1; i <= nodes; i++)
    {
        vector<int> inPath(nodes + 1, 0);
        if (!visited[i]){
            if (dfs(graph, i, visited, safeNode, inPath)){
                safeNode.insert(i);
            }
        }
    }
    for (auto it = safeNode.begin(); it != safeNode.end(); it++)
    {
        cout << *it <<", ";
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