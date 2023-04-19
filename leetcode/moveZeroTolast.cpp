#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3157/

void moveZeroes(vector<int> &nums)
{
    int l = nums.size();
    int zeros = 0;
    for (int i = 0; i < l; i++)
    {
        if (nums[i] == 0)
        {
            zeros++;
        }
    }
    int p1 = 0;
    int p2 = 0;
    while(true){
        if(!nums[p1])
            break;
        p1++;
        p2++;
    }

    p2++;

    while (p2 < l){

            if (nums[p2]){ /// nums[p2] not zero
                nums[p1] = nums[p2];
                nums[p2] = 0;
                p1++;
                p2++;
            }

            if (!nums[p2]){
                p2++;
            }
        }
        cout << nums[0];
        // while (zeros){
        //     nums[--l] = 0;
        //     zeros--;
        // }
}


int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    cin >> t;
    vector<int> v = {1};
    moveZeroes(v);

    return 0;
}