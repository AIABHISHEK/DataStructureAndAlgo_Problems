#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
//problem link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
/**
 * @brief
 * Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element.
 */

/**
 * Calculates whether the total sum of integer division and rounding upto nearest greatest integer, of all 
 * the elements in the given vector divided by the divisor is less than or 
 * equal to the given threshold.
 *
 * @param nums the vector of integers to be divided and summed up
 * @param threshold the maximum threshold value
 * @param divisor the divisor to use for integer division
 *
 * @return true if the total sum is less than or equal to the threshold, 
 *         false otherwise
 *
 * @throws None
 */
bool belowOrEqualThreshold(vector<int> &nums, int threshold, int divisor)
{
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += nums[i] / divisor;
        if (nums[i] % divisor != 0)
            total++;
    }
    return (total <= threshold);
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int start = 1;
    int end = nums[max_element(nums.begin(), nums.end()) - nums.begin()];
    int ans;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (belowOrEqualThreshold(nums, threshold, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<int> nums = {1, 2, 5, 9};
int threshold = 6;
cout<<smallestDivisor(nums, threshold);
return 0;
}