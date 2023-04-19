#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
//

int solve(int arr[], int n, int min)
{

    if (n <= 0)
        return 0;

    if (min > arr[n - 1])
    {
        return max(1 + solve(arr, n - 1, arr[n - 1]), solve(arr, n - 1, min));
    }

    else
    {
        return solve(arr, n - 1, min);
    }
}

int solve_dp(int arr[], int n)
{
    int t[n + 1];
    
    for (int i = 0; i <= n; i++)
    {
        t[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if (arr[i - 1] > arr[j - 1] && t[j] > t[i])
            {
                t[i] = t[j];
            }
        }
        t[i]++;
    }
    int ans = 0;
    for (auto i : t)
    {
        ans = max(ans, i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int n;
    int arr[] = {10, 6, 14, 1, 9, 5, 13, 3, 3, 3, 15, 56, 67, 45, 57, 90};
    cout << solve(arr, 16, INT_MAX) <<endl;
    cout << solve_dp(arr, 16); // maximum value
    return 0;
}