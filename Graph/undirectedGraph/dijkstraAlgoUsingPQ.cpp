#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

// shortest path in the undirected weighted(positive) graph using dijkstra algorithm

using namespace std;

void solve(vector<pair<int,int>> graph [], int src, int nodes){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    vector<int> dis(nodes, INT32_MAX);
    dis[0] = 0;
    while(!pq.empty()){
        pair<int, int> node = pq.top();
        pq.pop();

        for (int i = 0; i < graph[node.second].size(); i++){
            if (graph[node.second][i].second + node.first < dis[graph[node.second][i].first])
            {
                pq.push({graph[node.second][i].second + node.first, graph[node.second][i].first});
                dis[graph[node.second][i].first] = graph[node.second][i].second + node.first;
            }
        }
    }
    for(auto it : dis){
        cout << it << " ";
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

int v, e;
cin >> v >> e;
int w;
vector<pair<int, int>> graph[v + 1]; // graph start from index 1
for (int i = 0; i < e; i++)
{
    int a, b;
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
}
solve(graph, 0, v);
return 0;
}