#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

/***
 * You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.
*/

/**
 * Checks if all elements in a range of a vector are equal.
 *
 * @param nums The vector of integers.
 * @param i The starting index of the range.
 * @param j The ending index of the range (exclusive).
 *
 * @return True if all elements in the range are equal, false otherwise.
 *
 * @throws None.
 */
bool checkEqual(vector<int> &nums, int i, int j)
{
    for (; i < j - 1; i++)
    {
        if (nums[i] != nums[i + 1])
            return false;
    }
    return true;
}
/**
 * Check if the elements in the vector nums are strictly increasing from index i to index j.
 *
 * @param nums the vector of integers
 * @param i the starting index (inclusive)
 * @param j the ending index (exclusive)
 *
 * @return true if the elements are strictly increasing, false otherwise
 *
 * @throws None
 */
bool increasing(vector<int> &nums, int i, int j)
{
    for (; i < j - 1; i++)
    {
        if (nums[i + 1] - 1 != nums[i])
            return false;
    }
    return true;
}

/**
 * Checks if it is possible to reach the end of the vector by following certain rules.
 *
 * @param nums a reference to a vector of integers
 * @param i an integer representing the current index
 * @param dp a reference to a vector of integers
 *
 * @return a boolean value indicating if it is possible to reach the end
 *
 * @throws None
 */
bool solve(vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size())
        return true;
    if (i == nums.size() - 1)
        return false;

    if (dp[i] != -1)
        return dp[i];
    int k = i;
    if (k + 3 <= nums.size() && checkEqual(nums, k, k + 3))
    {
        return dp[i] = solve(nums, k + 2, dp) || solve(nums, k + 3, dp);
    }
    else if (checkEqual(nums, k, k + 2))
    {
        return dp[i] = solve(nums, k + 2, dp);
    }
    else if (k + 3 <= nums.size() && increasing(nums, k, k + 3))
    {
        return dp[i] = solve(nums, k + 3, dp);
    }

    return dp[i] = false;
}
bool validPartition(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return solve(nums, 0, dp);
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio

    return 0;
}