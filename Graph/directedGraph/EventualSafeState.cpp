#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;



void solve(vector<int> graph[], int nodes){
    cout << "hell";
    vector<int> graph_[nodes];
    vector<int> indegree(nodes, 0);
    vector<int> safeNodes;
    // set<int> safeNodes;
    //first reverse the direction for the directed graph nodes 0 -- > 1 to 1 -- > 0
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < graph[i].size(); j++){
            graph_[graph[i][j]].push_back(i);
            indegree[i] = indegree[i] + 1;
        }
    }

    queue<int> q;
    for (int i = 0; i < nodes; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(q.size()){
        int p = q.front();
        q.pop();
        safeNodes.push_back(p);
        for (int i = 0; i < graph_[p].size(); i++){
            indegree[graph_[p][i]]--;
            if(indegree[graph_[p][i]] == 0){
                q.push(graph_[p][i]);
            }
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
    for(auto it:safeNodes){
        cout << it  <<", ";
    }
}
        int main()
        {
            // ios_base::sync_with_stdio(false); // fastio
            // cin.tie(NULL);                    // fastio
            int v, e;
            cin >> v >> e;
            vector<int> graph[v]; // graph start from index 1
            for (int i = 0; i < e; i++)
            {
                int a, b;
                cin >> a >> b; /// a ---> b
                graph[a].push_back(b);
            }
            solve(graph, v);
            return 0;
        }