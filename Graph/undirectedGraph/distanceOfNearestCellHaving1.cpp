#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

vector<vector<int>> solve(vector<vector<int>> matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dis(m, vector<int>(n, 0));
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j])
            {
                visited[i][j] = 1;
                q.push({0, {i, j}});
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }
    vector<int> a = {-1, 0, 1, 0};
    vector<int> b = {0, 1, 0, -1};

    while (!q.empty())
    {
        pair<int, pair<int, int>> p = q.front();
        q.pop();
        int i = p.second.first;
        int j = p.second.second;
        int d = p.first;
        dis[i][j] = d;
        for (int k = 0; k < 4; k++)
        {
            if ( (i + a[k] >= 0) && (i + a[k] < m) && (j + b[k] >= 0) && (j + b[k] < n) && !(visited[i + a[k]][j + b[k]]) ){
                q.push({d + 1, {i + a[k], j + b[k]}});
                visited[i + a[k]][j + b[k]] = 1;
            }
        }
    }
    return dis;
}
    int main()
    {
        ios_base::sync_with_stdio(false); // fastio
        cin.tie(NULL);                    // fastio
        int t;
        cin >> t;
        int m = 3;
        int n = 3;
        vector<vector<int>> v = {
            {1, 0, 0, 1},
            {1, 0, 0, 0},
            {0, 1, 0, 1}};
            // ans
        //  1 2 3 2
        //  0 1 2 1 
        //  1 0 1 0
         vector<vector<int>> dis = solve(v);
        for (auto it : dis)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return 0;
    }