#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;


// minimum of difference between two subsets
//  given a array divide array two subset such that the difference of sum of elements of subsets is minimum
//  s1 - s2 is minimum
// that is we have to find minimum value of s1 - s2
//  since we do not know the s1 and s2 but we can find the range of s1 and s2
//  range sum of elements of array and s1 + s2  is range
//  so s1 - s2 minimum is range - 2*s1 is minimum
//  to make sure that it positive consider s1 always less than or equal to range/2
//  how to find all the possible values which are possible
// we can find that by subset sum problem method


//in this problem use top down approach since recurssive all table not filled completely inmost cases


int dp[100][100];
int solve(int a[], int sum, int length) {

    if (sum == 0) {
        return 1;
    }

    if (length == 0) {
        return 0;
    }

    if (dp[length][sum] > -1) {
        return dp[length][sum]; //

    }

    if (a[length - 1] <= sum) {

        return dp[length][sum] = (solve(a, sum - a[length - 1], length - 1) || solve(a, sum, length - 1)); //
    }

    else {
        return dp[length][sum] = solve(a, sum, length - 1);
    }
}
int solve_top_down(int a[], int sum, int length) {
    int t[length + 1][sum + 1];

    for (int i = 0; i < sum + 1; i++)
        t[0][i] = 0;

    for (int i = 0; i < length + 1; i++)
        t[i][0] = 1;


    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j) {
                t[i][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
            }
            else {
                t[i][j] = t[i - 1][j];
            }
        }

    }

    int min_ = INT_MAX;
    vector<int> v;
    cout << sum << endl;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (t[length][i] == 1)
        {
            v.push_back(i);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
        min_ = min(min_, sum - (2 * v[i]));
    }
    cout << " min " << min_ << endl;


}

void solve_diff(int a[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }

    // memset(dp, -1, sizeof(dp));
    solve_top_down(a, sum, length);

}

int main() {
    
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    // cin >> t;
    int a[] = { 1, 2, 7 };
    solve_diff(a, 3);
    return 0;
    
}