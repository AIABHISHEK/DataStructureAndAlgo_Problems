#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void solve(vector<pair<int, int>> graph[], int src, int end, int nodes){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    vector<pair<int, int>> dis(nodes, {INT32_MAX, INT32_MAX});
    dis[0] = {0, 0};// 1st part of pair dis 2n from where it is coming

    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        for (int i = 0; i < graph[p.second].size(); i++){
            if (p.first + graph[p.second][i].second < dis[graph[p.second][i].first].first){
                pq.push({p.first + graph[p.second][i].second, graph[p.second][i].first});
                dis[graph[p.second][i].first] = {p.first + graph[p.second][i].second, p.second};
            }
        }
    }
    int i = end;
    for (int j = 0; j < dis.size(); j++){
        cout << dis[j].first << " " << dis[j].second << " " << endl;
    }
        while (i != 0)
        {
            cout << i << " ";
            i = dis[i].second;
        }
        cout << i;
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
solve(graph, 0, 5, v);

return 0;
}