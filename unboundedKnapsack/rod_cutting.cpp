#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// rod cutting problem
// given length array and price array and we have rod  which need to be cut so that we get profit maximum
int dp[100][100];

int solve(int v[], int length[], int n, int rod_l) { // n length of v, length array , v is price array, rod_l length of rod

    if (rod_l == 0)
        return 0; //
    if (n == 0)
        return 0; //

    if (dp[n][rod_l] > -1)
        return dp[n][rod_l];

    if (length[n - 1] <= rod_l) {
        return dp[n][rod_l] = max(v[n - 1] + solve(v, length, n, rod_l - length[n - 1]), solve(v, length, n - 1, rod_l));
    }
    else {
        return dp[n][rod_l] = solve(v, length, n - 1, rod_l);
    }
}

int solve_dp(int v[], int length[],int n, int rod_l) {
    memset(dp, -1, sizeof(dp)); //
    return solve(v, length, n, rod_l);
}

int main() {
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int t;

// cin >> t; 

return 0;
}