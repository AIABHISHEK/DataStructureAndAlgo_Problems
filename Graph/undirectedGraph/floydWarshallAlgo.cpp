#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// floyd Warshall algorithm
//  all shortest path

void solve(vector<vector<int>> arr, int n)
{

    for (int k = 0; k < n; k++)
    {
        // a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
        // shortest path via i
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }
    // for i , j where i == j arr[i][j] == 0 if not negative cycle
    // for (int i = 0; i < n; i++){
    //     if(arr[i][i] < 0){
    //         cout << "Negative cycle";
    //         return;
    //     }
    // }
    for (auto it : arr)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int m = 10e7;
    cout << m << endl;
    // vector<vector<int>> v = {
    //     {0, 2, m, m},
    //     {1, 0, 3, m},
    //     {m, m, 0, m},
    //     {3, 5, 4, 0}};
    vector<vector<int>> v = {
        {0, 2, m},
        {2, 0, 3},
        {m, 3, 0}};
    solve(v, 4);
    return 0;
}