#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void dfs(vector<vector<int>> matrix, int i, int j, vector<char> &v, vector<vector<int>> &visited){
    int m = matrix.size();
    int n = matrix[0].size();
    visited[i][j] = 1;
    if(j + 1 < n && !visited[i][j + 1] && matrix[i][j + 1] == 1){
        v.push_back('R');
        dfs(matrix, i, j + 1, v, visited);
    }
    if (i + 1 < m && !visited[i + 1][j] && matrix[i + 1][j] == 1){
        v.push_back('D');
        dfs(matrix, i + 1, j, v, visited);
    }
    if (j - 1 >= 0 && !visited[i][j - 1] && matrix[i][j - 1] == 1){
        v.push_back('L');
        dfs(matrix, i, j - 1, v, visited);
    }
    if (i - 1 >= 0 && !visited[i - 1][j] && matrix[i - 1][j] == 1){
        v.push_back('U');
        dfs(matrix, i - 1, j, v, visited);
    }
}

int solve(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    set<vector<char>> l;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            vector<char> v;
            if (!visited[i][j] && matrix[i][j] == 1){
                dfs(matrix, i, j, v, visited);
                l.insert(v);
            }
        }
    }
    return l.size();
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<vector<int>> v = {
    {0, 1, 0, 0, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 1, 1}};
cout<<solve(v);
return 0;
}