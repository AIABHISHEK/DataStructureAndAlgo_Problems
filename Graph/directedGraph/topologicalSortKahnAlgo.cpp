#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void solve(vector<int> graph[], int nodes){
    
    vector<int> topoSorted;
    vector<int> indegree(nodes, 0);
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < graph[i].size(); j++){
            indegree[graph[i][j]] = indegree[graph[i][j]] + 1;
        }
    }
    queue<int> q;
    for (int i = 0; i < nodes; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }

    while (q.size()){
        int p = q.front();
        topoSorted.push_back(p);
        q.pop();
        for (int i = 0; i < graph[p].size(); i++){
            indegree[graph[p][i]]--;
            if (indegree[graph[p][i]] == 0){
                q.push(graph[p][i]);
            }
        }
    }
    for (auto i : topoSorted){
        cout << i << " ";
    }
}
    int main(){
        ios_base::sync_with_stdio(false); // fastio
        cin.tie(NULL);                    // fastio
        int v, e;
        cin >> v >> e;
        vector<int> graph[v]; // graph start from index 1
        for (int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b; /// a ---> b
            graph[a].push_back(b);
        }
        solve(graph, v);
        return 0;
    }