#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// dijkstra algo uisng set algorithm 
void solve(vector<pair<int, int>> graph [], int nodes, int src){
    set<pair<int, int>> st;
    vector<int> dis(nodes, INT32_MAX);
    st.insert({0, src});
    while(!st.empty()){
        auto it = st.begin();
        pair<int, int> p = *it;
        st.erase(it);
        for (int i = 0; i<graph[p.second].size(); i++){
            if (graph[p.second][i].second + p.first < dis[graph[p.second][i].first]){
                if (dis[graph[p.second][i].first] != INT32_MAX)
                    st.erase({dis[graph[p.second][i].first], graph[p.second][i].first});

                st.insert({graph[p.second][i].second + p.first, graph[p.second][i].first});
                dis[graph[p.second][i].first] = graph[p.second][i].second + p.first;
            }
        }
    }
}


int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio


return 0;
}