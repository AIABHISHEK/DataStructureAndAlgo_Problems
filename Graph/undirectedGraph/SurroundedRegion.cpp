#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// replace all zeroes with x which are surrounded by x

void dfs(vector<vector<int>> matrix, vector<vector<int>> &visited, int j, int k)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> a = {-1, 0, 1, 0};
    vector<int> b = {0, 1, 0, -1};
    // while()
    for (int i = 0; i < 4; i++)
    {
        j = j + a[i], k = k + b[i];
        if (j < m && k < n && j >= 0 && k >= 0){
            if(!visited[j][k] && matrix[j][k] == 0){
                visited[j][k] = 1;
                dfs(matrix, visited, j, k);
            }
        }
    }
}

void solve(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<int> a = {0, 1, m - 1, 1};
    vector<int> b = {0, 0, 0, n - 1};
    int r = 0;
    int c = 1;
    for (int i = 0; i < 4; i++)
    {
        int j = a[i], k = b[i];
        while (j < m && k < n)
        {
            if (matrix[j][k] == 0 && !visited[j][k])
            {
                visited[j][k] = 1;
                dfs(matrix, visited, j, k);
                
            }
            j = j + r;
            k = k + c;
        }
        int temp = r;
        r = c;
        c = temp;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited[i][j] << " ";
            if(!visited[i][j]){
                matrix[i][j] = 1;
            }
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout << endl;
    }
}
        int main()
        {
            ios_base::sync_with_stdio(false); // fastio
            cin.tie(NULL);                    // fastio
            cout << "hello";
            vector<vector<int>> v = {
                {0, 1, 1, 1, 1},
                {1, 1, 0, 1, 1},
                {1, 0, 0, 1, 1},
                {1, 0, 1, 0, 1},
                {1, 1, 1, 0, 0}};
            solve(v);
            return 0;
        }