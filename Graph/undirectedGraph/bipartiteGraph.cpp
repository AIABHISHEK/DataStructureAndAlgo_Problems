#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// if we can color all the nodes with no adajacent nodes with same color
// all linear graph with no cycyle are bipartite
// cyclic graph with even no of nodes in the cycle are bipartite
// // cyclic graph with odd no of nodes in the cycle are not bipartite

bool solve(vector<int> graph[], int nodes){
    queue<int> q;
    vector<int> color(nodes + 1, 0);
    q.push(1);
    color[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for (int i = 0; i < graph[node].size(); i++){
            int n = graph[node][i];
            if (color[node] == color[n]){
                    return false;
                } 
            else if (!color[n]){
                color[n] = 1;
                if (color[node] == 1)
                    color[n] = 2;
                q.push(n);
            }
        }
    }
    return true;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int v, e;
cin >> v >> e;
vector<int> graph[v + 1]; // graph start from index 1
for (int i = 0; i < e; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
}
cout << solve(graph, v);
return 0;
}