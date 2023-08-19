#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// Given an integer array nums and an integer k, return the kth largest element in the array.

//     Note that it is the kth largest element in the sorted order,
//     not the kth distinct element.


    int
    sort(vector<int> & nums, int i, int j)
{
    int prev = i - 1;
    int curr = i;
    int pivot = j;
    while (curr < j)
    {
        if (nums[curr] > nums[pivot])
        {
            prev++;
            swap(nums[curr], nums[prev]);
        }
        curr++;
    }
    prev++;
    swap(nums[pivot], nums[prev]);
    return prev;
}

int quickselect(vector<int> &nums, int i, int j, int k)
{
    if (i <= j)
    {
        int pivot = j;
        int index = sort(nums, i, j);
        if (index + 1 == k)
            return nums[index];
        if (index + 1 < k)
            return quickselect(nums, index + 1, j, k);
        else if (index + 1 > k)
            return quickselect(nums, i, index - 1, k);
    }
    return 0;
}

int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    return quickselect(nums, 0, n - 1, k);
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 1;
    // Output: 
    //using STL 

    // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    // cout << nums[k - 1];
    
    // partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
    // cout << nums[k - 1];

    cout << findKthLargest(nums, k);
    return 0;
}