#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// given array find array can be divided into two subsets whose sum are equal

// first find sum all the elements of the array and if it is odd no two  such subsets exist else if it is even
// divide the sum by 2 and then find that their exist subset whose sum is equal to sum/2  ->>> similar to subset sum problem

/// recursive
bool solve(int a[], int length, int sum)
{
    if (sum == 0)
        return true;

    if (length == 0)
        return false;

    if (a[length - 1] <= sum)
    {
        return solve(a, length - 1, sum - a[length - 1]) || solve(a, length - 1, sum);
    }
    else
    {
        return solve(a, length - 1, sum);
    }
}

// dp recurssive
int dp[100][100]; //
bool solve_dp(int a[], int length, int sum)
{
    if (sum == 0)
        return true;

    if (length == 0)
        return false;


    if(dp[length][sum] > -1)
        return dp[length][sum];    

    if (a[length - 1] <= sum)
    {
        return dp[length][sum] = solve(a, length - 1, sum - a[length - 1]) || solve(a, length - 1, sum);
    }
    else
    {
        return dp[length][sum] = solve(a, length - 1, sum);
    }
}

bool solve_(int a[], int length)
{
    int sum = 0; //
    for (int i = 0; i < length; i++)
    {
        sum += a[i];
    }
    sum /= 2;
    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        return solve(a, length, sum);
    }
}

//  top down approach

bool solve_top_down(int a[], int length, int sum)
{
    int t[length + 1][sum + 1];

    for (int i = 0; i < length; i++)
    {
        t[0][i] = 0;
        t[i][0] = 1;
    }

    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j < length; j++)
        {
            if(a[i - 1] <= sum)
            {
                t[i - 1][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i - 1][j] = t[i - 1][j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    cin >> t;

    return 0;
}