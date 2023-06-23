#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    return nums[k - 1];
    // using partial sort
    partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
    return nums[k - 1];
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    string s = new string(123);
    
    return 0;
}