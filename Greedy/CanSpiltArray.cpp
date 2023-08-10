#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// problem link https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/

/**
 * @brief You are given an array nums of length n and an integer m. You need to determine if it is possible to split the array into n non-empty arrays by performing a series of steps.

In each step, you can select an existing array (which may be the result of previous steps) with a length of at least two and split it into two subarrays, if, for each resulting subarray, at least one of the following holds:

The length of the subarray is one, or
The sum of elements of the subarray is greater than or equal to m.
Return true if you can split the given array into n arrays, otherwise return false.

Note: A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * @return int
 */

// greed Approach since we can we have make n splits which is size of array we can start removing from ends (of array either from start or end index),  when we have 3 elements left then there must contiguous elements such nums[i] + nums[i+1] >= m so we can split one element form it easily
// so we have to check if there exists nums[i]+nums[i+1] >= m

bool canSplitArray(vector<int> &nums, int m)
{
    int n = nums.size();
    if (n < 3)
        return 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] + nums[i - 1] >= m)
            return true;
    }
    return false;
}

// Using DP


int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio

    // nums = [ 2, 2, 1 ], m = 4 Output : true
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int m = 5;
    // Output: true
    //  nums = [ 1, 2, 3, 4, 5 ], m = 5
    //  Output : false
    // vector<int> nums = {1, 1, 1, 1, 1, 1, 1};
    // int m = 7;
    // Output : true
    // cout << canSplitArray(nums, m);


    cout<<canSplitArray(nums, m);
    return 0;
}