#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

bool isvalid(vector<vector<int>> arr, int i, int j, int n, vector<pair<int, int>> pq)
{
    for (int k = 0; k < pq.size(); k++)
    {
        pair<int, int> p = pq[k];
        if (p.first == i){
            return false;
        }
        int d1 = i - p.first;
        int d2 = j - p.second;
        if (abs(d1) == abs(d2)){
            return false;
        }
    }
    for (int k = 0; k < pq.size(); k++){
        pair<int, int> p = pq[k];  
    }
    return true;
}

void Nqueens(vector<vector<int>> &arr, int j, int n, vector<pair<int, int>> &pq, vector<vector<pair<int, int>>> &ans)
{
    if (j >= n && pq.size() == n){
        ans.push_back(pq);
        for (auto it : arr){
            for (auto i : it){
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    if (j >= n)
        return;
    for (int i = 0; i < n; i++){
        if (isvalid(arr, i, j, n, pq)){
            pq.push_back({i, j});
            arr[i][j] = 1;
            Nqueens(arr, j + 1, n, pq, ans);
            pq.pop_back();
            arr[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    cin >> t;
    vector<vector<int>> arr(t, vector<int>(t, 0));
    vector<pair<int, int>> pq;
    vector<vector<pair<int, int>>> ans;
    Nqueens(arr, 0, t, pq, ans);
    // for (auto it : ans)
    // {
    //     for (auto i : it)
    //     {
    //         cout << i.first << "  " << i.second << " , ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}