#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// bfs traversal

vector<int> bfs(vector<int> graph[], int nodes){
    vector<int> bfs_seq;
    vector<int> visited(nodes + 1, 0);

    for (int i = 1; i <= nodes; i++){
        if (!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(q.size()){
                int e = q.front();
                q.pop();
                bfs_seq.push_back(e);
                for (int k = 0; k < graph[e].size(); k++){
                    int node = graph[e][k];
                    if (!visited[node])
                    {
                        q.push(node);
                        visited[node] = true;
                    }
                }
            }
        }
    }
    return bfs_seq;
}

int main(){                   // fastio
    int v, e;
    cin >> v >> e;
    vector<int> graph[v + 1]; // graph start from index 1
    for (int i = 0; i <e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> bfs_seq = bfs(graph, v);
    for (auto i : bfs_seq)
    {
        cout << i << " ";
    }
    return 0;
}