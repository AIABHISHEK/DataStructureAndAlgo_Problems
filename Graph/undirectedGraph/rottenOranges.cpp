#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
//we have find the time all oranges will get rotten 2 - rotten orange 1 fresh  0 - no orange
// unit time to rot each neighbour  up down left right

// int bfs(vector<vector<int>> matrix, queue<pair<pair<int, int>,int>> q){

// }

int rottenOrnages(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> v(m,vector<int>(n,0));
    queue <pair<pair<int, int>, int>> q;
    //store all the index where 2 is present and store time  = 0
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == 2){
                q.push({{i, j}, 0});
                v[i][j] = 1;
            }
            else{
                v[i][j] = 0;
            }
        }
    }
    
    int tm = 0;
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int t = p.second;
        int i = p.first.first;
        int j = p.first.second;
        tm = max(tm, t);
        if ((i > 0) && (!v[i - 1][j]) && (matrix[i - 1][j] != 0)) 
        {
            v[i - 1][j] = 1;
            q.push({{i - 1, j}, t + 1});
        }
        if ((j < n - 1) && (!v[i][j + 1]) && (matrix[i][j + 1] != 0))
        {
            v[i][j + 1] = 1;
            q.push({{i, j + 1}, t + 1});
        }
        if ((i < m - 1) && (!v[i + 1][j]) && (matrix[i + 1][j] != 0))
        {
            v[i + 1][j] = 1;
            q.push({{i + 1, j}, t + 1});
        }
        if ((j > 0) &&(!v[i][j - 1]) && (matrix[i][j - 1] != 0))
        {
            v[i][j - 1] = 1;
            q.push({{i, j - 1}, t + 1});
        }
    }
    
    return tm;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<vector<int>> v = {
    {2, 0, 2, 1, 1, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 0},
    {0, 0, 0, 2, 1, 1},
    {1, 0, 0, 0, 0, 1}};
int a = rottenOrnages(v);
cout << a;
return 0;
}