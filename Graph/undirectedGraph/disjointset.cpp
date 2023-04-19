#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// union by rank and by size
class disjointset
{ 
private:
    

public:
vector<int> rank, parent, size;
    disjointset(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
        // find parent 
        // path compression
        //1 -> 2 - > 3
        /* 
        1 is ultimate parent 
        */
    int ul_parent(int v){
        if(v == parent[v])
            return v;
        return parent[v] = ul_parent(parent[v]);
    }
    //connect u to v
   //u -- > v
    void UnionByRank(int u, int v){
        int ulp_u = ul_parent(u);
        int ulp_v = ul_parent(v);
        //if parent of u and v that are in the same graph
        if(ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }

        //if connect v->u then parent[v] = ultp_u
        
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

};

//function to add two number

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

disjointset st(7);
st.UnionByRank(1, 2);
st.UnionByRank(2, 3);
st.UnionByRank(4, 5);
st.UnionByRank(6, 7);
st.UnionByRank(5, 6);
for(int i = 0; i<7; i++){
    cout<<st.rank[i]<<" ";
}
cout<<endl;
cout << st.ul_parent(3) <<" , "<< st.ul_parent(7)<< endl;
if (st.ul_parent(3) == st.ul_parent(7))
{
    cout << "same\n";
}
else{
    cout << "not same\n";
}

st.UnionByRank(3, 7);

cout << st.ul_parent(3) << " , " << st.ul_parent(7) << endl;
if (st.ul_parent(3) == st.ul_parent(7))
{
    cout << "same\n";
}
else
{
    cout << "not same\n";
}

return 0;
}