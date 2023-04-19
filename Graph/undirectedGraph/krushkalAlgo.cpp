#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;


// krushkal algo for finding mst
class disjoint{
    private:
        vector<int> rank, parent;
    public:
    disjoint(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int ult_parent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = ult_parent(parent[node]);
    }

    void UnionByRank(int u, int v){
        int ult_u = ult_parent(u);
        int ult_v = ult_parent(v);
        if(ult_u == ult_v)
            return;

        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }

        else if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        }

        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

void mst(vector<pair<int, pair<int, int>>> graph, int nodes)
{
    sort(graph.begin(), graph.end());
    int mstSum = 0;
    for(auto it: graph){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        disjoint d(nodes);
        if(d.ult_parent(u) != d.ult_parent(v)){
            mstSum += wt;
            d.UnionByRank(u, v);
        }
    }
    cout << mstSum;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

return 0;
}