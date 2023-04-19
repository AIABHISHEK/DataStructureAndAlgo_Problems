#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void solve(vector<pair<int, int>> graph[], int v, int sourceNode){
    stack<int> topsorted;
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++){
        for (int j = 0; j < graph[i].size(); j++){
            indegree[graph[i][j].first]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topsorted.push(node);
        for (int i = 0; i < graph[i].size(); i++){
            indegree[graph[node][i].first]--;
            if(indegree[graph[node][i].first] == 0){
                q.push(graph[node][i].first);
            }
        }
    }

    vector<int> distance (v, INT64_MAX);
    distance[sourceNode] = 0;
    while(!topsorted.empty()){
        int node = topsorted.top();
        topsorted.pop();
        for (int i = 0; i < graph[node].size(); i++){
            if ((graph[node][i].second + distance[node]) < distance[graph[node][i].first])
                distance[graph[node][i].first] = graph[node][i].second + distance[node];
        }
    }
    for(auto it:distance){
        cout << it << " ";
    }
}


int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

int v, e , source;
cin >> v >> e;
vector<pair<int, int>> graph[v];

for (int i = 0; i < e; i++)
{
    int a, b, w;
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
}
solve(graph, v, source);

return 0;
}