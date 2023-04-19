#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

bool dfs(vector<int> graph[], vector<int> visited, int i, int p){
    visited[i] = true;
    for (int j = 0; j < graph[i].size(); j++){
        if (!visited[graph[i][j]])
        {
            if (dfs(graph, visited, graph[i][j], i))
                return true;
        }
        if (visited[graph[i][j]] == true && graph[i][j] != p)
        {
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
vector<int> visited(v + 1, 0);
for (int i = 0; i < e; i++)
{
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}
bool t = dfs(graph, visited, 0, -1);

cout << t;

return 0;
}