#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
/*
graph is m * n matrix with values 0 or 1 where 0 means water and 1 means land we need to find number of islands
// in order to solve the above problem we need to make amtrix of same dimension to keep track of the visited
*/

void bfs(int i, int j, vector<vector<int>> graph, vector<vector<int>> &visited)
{
    int m = graph.size();
    int n = graph[0].size();
    visited[i][j] = true;
    queue<pair<int, int>> q;
    visited[i][j] = true;
    q.push(make_pair(i, j));
    // q.push({i ,j})
    while (q.size()){
        pair<int, int> pf = q.front();
        q.pop();
        int f = pf.first;
        int s = pf.second;
        if (f > 0 && s < m)
        {
            if (!(visited[f - 1][s]) && graph[f - 1][s])
            {
                visited[f - 1][s] = true;
                q.push({f - 1, s});
            }
        }
        if(f > 0 && s < m - 1)
        {
            if (!(visited[f - 1][s + 1]) && graph[f - 1][s + 1])
            {
                visited[f - 1][s + 1] = true;
                q.push({f - 1, s  + 1});
            }
        }
        if(s < m - 1){
            if (!(visited[f][s + 1]) && graph[f][s + 1])
            {
                visited[f][s + 1] = true;
                q.push({f, s + 1});
            }
        }
        if (f < n - 1 && s < m - 1){
            if (!(visited[f + 1][s + 1]) && graph[f + 1][s + 1])
            {
                visited[f + 1][s + 1] = true;
                q.push({f + 1, s + 1});
            }
        }
        if(f < n - 1){
            if (!(visited[f + 1][s]) && graph[f + 1][s])
            {
                visited[f + 1][s] = true;
                q.push({f + 1, s});
            }
        }
        if(s > 0){
            if (!(visited[f][s - 1]) && graph[f][s - 1])
            {
                visited[f][s - 1] = true;
                q.push({f, s - 1});
            }
        }
        if(f > 0 && s > 0){
            if (!(visited[f - 1][s - 1]) && graph[f - 1][s - 1])
            {
                visited[f - 1][s - 1] = true;
                q.push({f - 1, s - 1});
            }
        }
    }
}

int countIslands(vector<vector<int>> graph)
{
    int m = graph.size();
    int n = graph[0].size();
    int count = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && graph[i][j])
            {
                count++;
                bfs(i, j, graph, visited);
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    vector<vector<int>> v = {
        {1, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 1}};
    cout << countIslands(v);
    return 0;
}