#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void solve(vector<int> graph [], int v, int sourceNode){
    vector<int> distance(v, INT32_MAX);
    distance[sourceNode] = 0;
    queue<int> q;
    q.push(sourceNode);

    while(!q.empty()){
        int p = q.front();
        q.pop();
        for (int i = 0; i < graph[p].size(); i++){
            if(distance[p] + 1 < distance[graph[p][i]]){
                distance[graph[p][i]] = distance[graph[p][i]] + 1;
                q.push(graph[p][i]);
            }
        }
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

int v, e;
cin >> v >> e;
vector<int> graph[v + 1]; // graph start from index 1
for (int i = 0; i < e; i++)
{
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}


return 0;
}