#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// you are given a n X m binary matrix grid where 0 is water an 1 is land
// find number of 1(land) from where we can not move out of the grid can move up down left right
void solve(vector<vector<int>> matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            {
                if (matrix[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
    }
    vector<int> a = {-1, 0, 1, 0};
    vector<int> b = {0, 1, 0, -1};
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        for (int k = 0; k < 4; k++)
        {
            if ((i + a[k] >= 0) && (i + a[k] < m) && (j + b[k] >= 0) && (j + b[k] < n) && !(visited[i + a[k]][j + b[k]]) && matrix[i + a[k]][j + b[k]] == 1)
            {
                q.push({i + a[k], j + b[k]});
                visited[i + a[k]][j + b[k]] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited[i][j] << " ";
            if (matrix[i][j] && visited[i][j] == 0){
                // cout<<matrix[i][j] <<endl;
                count++;
            }
        }
        cout << endl;
    }
    cout << count;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    vector<vector<int>> v = {
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 0, 0}};
    solve(v);
    return 0;
}