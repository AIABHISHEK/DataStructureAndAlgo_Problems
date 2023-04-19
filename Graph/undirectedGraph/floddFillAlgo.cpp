#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// we are given 2d matrix where each value of a(i,j) represent a color we are given starting point  sr, sc we 
// have color all its connected neighbour up down left right which have same value as in sr ,sc

void dfs(vector<vector<int>> &matrix, int sr, int sc, int nc, int ic){
    int m = matrix.size();
    int n = matrix[0].size();
    matrix[sr][sc] = nc;
    if (sr > 0 && matrix[sr - 1][sc] == ic)
    {
        dfs(matrix, sr - 1, sc, nc, ic);
    }
    if (sr < m - 1 && matrix[sr + 1][sc] == ic){
        dfs(matrix, sr + 1, sc, nc, ic);
    }
    if (sc < n - 1 && matrix[sr][sc + 1] == ic)
    {
        dfs(matrix, sr, sc + 1, nc, ic);
    }
    if (sc > 0 && matrix[sr][sc - 1] == ic)
    {
        dfs(matrix, sr, sc - 1, nc, ic);
    }
}

void floddfill(vector<vector<int>> &matrix, int sr, int sc, int nc){
    int ic = matrix[sr][sc];
    dfs(matrix, sr, sc, nc, ic);
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
// int t;
// cin >> t;
vector<vector<int>> v = {
    {1, 2, 0, 1, 1, 0},
    {0, 2, 2, 1, 0, 0},
    {0, 0, 0, 2, 0, 0},
    {1, 2, 0, 0, 0, 0},
    {0, 0, 2, 1, 1, 1},
    {1, 0, 0, 0, 0, 1}};

floddfill(v, 1, 0, 3);

for (auto it : v)
{
    for (auto i : it)
    {
        cout << i << " ";
    }
    cout << endl;
}

return 0;
}