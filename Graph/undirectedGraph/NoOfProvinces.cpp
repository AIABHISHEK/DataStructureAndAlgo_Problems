#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// we have to find the number of the componenet int the graph whichare not connected
/* 1      4      6
    \     \     / \
    2     5    7   8
    /
    3
number of component is 3
*/

void dfs(int i,vector<int>graph[], vector<int> &visited){
    visited[i] = true;
    for (auto it : graph[i]){
        if(!visited[it]){
            dfs(it, graph, visited);
        }
    }
}


int count(vector<int> graph[], int nodes){
    vector<int> visited(nodes + 1, 0);
    int count = 0;
    for (int i = 1; i <= nodes; i++){
        if(!visited[i]){
            count++;
            dfs(i, graph, visited);
        }
    }
    return count;
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
cout << count(graph, v);
return 0;
}