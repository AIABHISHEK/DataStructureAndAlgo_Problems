#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int


// bellman ford algorithm
// first step initializes distances from the source to all vertices as infinite and distance to the source itself as 0. Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.
// This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph. Do following for each edge u-v 
// If dist[v] > dist[u] + weight of edge uv, then update dist[v] to
// dist[v] = dist[u] + weight of edge uv
// This step reports if there is a negative weight cycle in the graph. Again traverse every edge and do following for each edge u-v 
// ……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle” 
// The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle


using namespace std;
void solve(vector<vector<int>> graph, int nodes){
    vector<int> dis(nodes, INT32_MAX);
    dis[0] = 0;
    for (int i = 0; i<nodes - 1; i++){
        for (int j = 0; j < graph.size(); j++){
            int u = graph[j][0];
            int v = graph[j][1];
            int wt = graph[j][2];
            if (dis[u]!=INT32_MAX && dis[u] + wt < dis[v]){
                dis[v] = dis[u] + wt;
            }
        }
    }
    for(auto it : graph){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dis[u] != INT32_MAX && dis[u] + wt < dis[v])
        {
            cout << "negative cycle exists";
            return;
        }
    }
    for(auto it: dis){
        cout << it << " ";
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

int v, e;
cin >> v >> e;
int w;
vector<vector<int>> graph; // graph start from index 1
for (int i = 0; i < e; i++)
{
    int a, b;
    cin >> a >> b >> w;
    graph.push_back({a, b, w});
}
solve(graph, v);
return 0;
}