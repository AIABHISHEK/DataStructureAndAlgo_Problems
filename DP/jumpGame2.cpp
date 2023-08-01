#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

#define ll long long
/**
 * Calculates the minimum number of steps needed to reach the end of the given vector of integers.
 *
 * @param i The current index in the vector.
 * @param nums The vector of integers.
 * @param dp The vector used for memoization.
 *
 * @return The minimum number of steps needed to reach the end.
 *
 * @throws None
 */
ll solve(int i, vector<int> &nums, vector<int> &dp)
{
    if (i == nums.size() - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    ll a = INT_MAX;
    // take not
    int k = 1;
    while (k <= nums[i] && i + k < nums.size())
    {
        a = min((ll)1 + (ll)solve(i + k, nums, dp), a);
        k++;
    }
    return dp[i] = a;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio


return 0;
}