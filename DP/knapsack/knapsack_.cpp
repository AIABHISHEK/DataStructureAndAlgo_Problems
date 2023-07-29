#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;


// problem
/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

*/




// 0 - 1 knapsack recursive 
int solve(int w[], int v[], int maxWeight, int length) {
    // base condition

    if (length == 0 || maxWeight == 0)
        return 0;


    // main
    if (w[length - 1] <= maxWeight) {
        return max(v[length - 1] + solve(w, v, maxWeight - w[length - 1], length - 1), solve(w, v, maxWeight, length - 1));
        // case when maxWeight greater then we have two choice either select that weight or do not select that weight
    }
    else if (w[length - 1] > maxWeight) {
        return solve(w, v, maxWeight, length - 1); // case when maxWeight is less than w[lenght-1]
    }

}

// 0 -1 knapsack dp

int arr[100][100]; // if we have length n we will make array  of length n + 1
int solve_dp(int w[], int v[], int maxWeight, int length) {
    if (length == 0 || maxWeight == 0) {
        return 0;
    }
    if (arr[length][maxWeight] > -1) {
        return arr[length][maxWeight];
    }

    if (w[length - 1] <= maxWeight) {
        return arr[length][maxWeight] = max(v[length - 1] + solve_dp(w, v, maxWeight - w[length - 1], length - 1), solve_dp(w, v, maxWeight, length - 1));
    }
    else if (w[length - 1] > maxWeight) {
        return arr[length][maxWeight] = solve_dp(w, v, maxWeight, length - 1);
    }
}

int knap(int w[], int v[], int maxWeight, int length) {
    memset(arr, -1, sizeof(arr));

    return solve_dp(w, v, maxWeight, length);
}



// top-down approach 
int solve_top_down(int w[], int v[], int maxWeight, int length) {
    int arr[length + 1][maxWeight + 1]; // array for memo

    // base condition implementation
    for (int i = 0; i < length; i++)
    {
        arr[i][0] = 0;
        arr[0][i] = 0;
    }

    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (w[i - 1] <= j)
                arr[i][j] = max(v[i - 1] + arr[i - 1][j - w[i - 1]], arr[i - 1][j]);
            else
                arr[i][j] = arr[i - 1][j];
        }

    }
    return arr[length][maxWeight];
}

int solve_(int v[], int w[], int c, int n)
{

    // int t[n + 1][c + 1];
    vector<vector<int>> t(n + 1, vector<int>(c + 1));
    for (int i = 0; i <= n; i++) {
        t[i][0] = 0;
        cout << t[i][0] << " ";
    }
    for (int i = 0; i <= c; i++) {
        t[0][i] = 0;
    }


    // for (int i = 0; i < n + 1; i++)
    //     for (int j = 0; j < c + 1; j++)
    //     {
    //         if (i == 0 || j == 0)
    //             t[i][j] = 0;
    //     }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < c+1; j++)
        {
            if (w[i - 1] <= j)
            {
                t[i][j] = max(v[i - 1] + t[i - 1][j - w[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][c];
}

int main() {

    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL); // fastio

    int n, c;
    cin >> n;    //Reading input from STDIN
    // Writing output to STDOUT
    cin >> c;
    int v[n];
    int w[n];
    // cout << n << c;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int p = solve_(v, w, c, n);
    cout <<"this is "<< p << endl;
    return 0;
}