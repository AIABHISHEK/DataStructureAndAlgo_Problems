#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// count the number of subsets with given difference d
//  we divide the array into two subsets with the differnce of d and count the number of different possible subsets
//  s1 - s2 = d   ---> given
//  s1 + s2 = sum array elements
//  we can get s1 = d + sum array elements
//  so now problem reduced to count subset problem

int dp[100][100];

int solve(int a[], int length, int s) {

    if (s == 0) {
        return 1;
    }
    if (length == 0) {
        return 0;
    }
    if (dp[length][s] > -1) {
        return dp[length][s];
    }

    if (a[length - 1] <= s) {
        return dp[length][s] = solve(a, length - 1, s - a[length - 1]) + solve(a, length - 1, s);
    }

    else {
        return dp[length][s] = solve(a, length - 1, s);
    }

}

int solve_count(int a[], int length, int d)
{
    memset(dp, -1, sizeof(dp));
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }
    int s = (d + sum) / 2;
    return  solve(a, length, s);
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    // cin >> t;
    int a[] = { 1, 1, 2, 3 };
    cout << solve_count(a, 4, 1);
    return 0;
}