#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

// https : // leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3260/

void sortArrayByParity(vector<int> &nums){

    int l = nums.size();
    int j = 0;
    for (int i = 0; i < l; i++){
        if(nums[i]%2 == 0){
            swap(nums[j], nums[i]);
            j++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    // int t;
    // cin >> t;
    vector<int> arr = {3, 0, 2, 4};
    sortArrayByParity(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    
    return 0;
}