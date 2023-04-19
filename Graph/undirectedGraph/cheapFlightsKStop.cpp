#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void solve(vector<pair<int, int>>graph[], int src, int des, int stops, int nodes){
    // graph --> graph[i][j] = i -- > graph[i][j].first with weight graph[i][j].second
    queue<pair<int, int>> pq;
    pq.push({0, src});
    vector<pair<int, int>> dis(nodes, {INT32_MAX, 0});
    dis[0] = {0, 0}; // distance , stops
    while(!pq.empty()){
        pair<int, int> p = pq.front();
        pq.pop();
        int node = p.second;
        int cost = p.first;
        for (int i = 0; i<graph[node].size(); i++){
            
            if (dis[graph[node][i].first].second <= stops){
                if (cost + graph[node][i].second < dis[graph[node][i].first].first){
                    // cout << cost + graph[node][i].second << " , " << endl;
                    // cout << cost + graph[node][i].second << " , " << dis[graph[node][i].first].first <<" , "<<graph[node][i].first << endl;
                    pq.push({cost + graph[node][i].second, graph[node][i].first});
                    dis[graph[node][i].first] = {cost + graph[node][i].second, dis[node].second + 1};
                }
            }
        }
    }
    cout<<dis[des].first<<endl;
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
}
solve(graph, 0, 3, 2, v);

return 0;
}