#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int


using namespace std;

void solve(vector<int> graph[], int nodes)
{
    int topoSortedNumber = 0;
    vector<int> indegree(nodes, 0);
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            indegree[graph[i][j]] = indegree[graph[i][j]] + 1;
        }
    }
    queue<int> q;
    for (int i = 1; i <= nodes; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int p = q.front();
        topoSortedNumber++;
        q.pop();
        for (int i = 0; i < graph[p].size(); i++)
        {
            indegree[graph[p][i]]--;
            if (indegree[graph[p][i]] == 0)
            {
                q.push(graph[p][i]);
            }
        }
    }
    if(topoSortedNumber == nodes)
        cout << true;
    else
        cout << false;
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