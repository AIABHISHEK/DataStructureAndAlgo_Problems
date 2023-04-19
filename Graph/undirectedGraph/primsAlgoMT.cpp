#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// find MST for given graph

void solve(vector<pair<int, int>> graph[], int nodes)
{ /// wt, node , parent
    // cout << "hell0";
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    // node , parent
    vector<pair<int, int>> mst;
    // mark visited when node is in mst
    vector<int> vis(nodes, 0);

    pq.push({0, 0, -1});
    while (!pq.empty())
    {
        vector<int> p = pq.top();
        pq.pop();
        int parent = p[2];
        int node = p[1];
        int wt = p[0];
        if (vis[node] == 1)
            continue;
        vis[node] = 1;
        if (parent != -1)
        {
            mst.push_back({node, parent});
        }
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (!vis[graph[node][i].first])
            {
                pq.push({graph[node][i].second,
                         graph[node][i].first,
                         node});
            }
        }
    }

    for (auto it : mst)
    {
        cout << it.first << " -- > " << it.second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int v, e;
    cin >> v >> e;
    int w;
    vector<pair<int, int>> graph[v]; // graph start from index 1
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    solve(graph, v);
    return 0;
}