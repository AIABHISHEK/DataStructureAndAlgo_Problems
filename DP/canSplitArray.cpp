#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// this problem is solved in file /Greedy/canSplitArray.cpp using Greedy approach

bool solve(vector<int> &nums, int m, int i, int j, int sum, vector<vector<int>> &dp)
{
    if (i == j || j - i == 1)
        return true;
    int total = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    bool a = false;
    if (sum - nums[i] >= m)
    {
        a = a || solve(nums, m, i + 1, j, sum - nums[i], dp);
    }
    if (sum - nums[j] >= m)
    {
        a = a || solve(nums, m, i, j - 1, sum - nums[j], dp);
    }
    return dp[i][j] = a;
}
bool canSplitArrayDP(vector<int> &nums, int m)
{
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    return solve(nums, m, 0, nums.size() - 1, accumulate(nums.begin(), nums.end(), 0), dp);
}
int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
int m = 5;
// Output: true
//  nums = [ 1, 2, 3, 4, 5 ], m = 5
//  Output : false
// vector<int> nums = {1, 1, 1, 1, 1, 1, 1};
// int m = 7;
// Output : true
// cout << canSplitArray(nums, m);

cout << canSplitArrayDP(nums, m);
return 0;
}