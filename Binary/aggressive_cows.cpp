#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int
// problem link https://practice.geeksforgeeks.org/problems/aggressive-cows/0
// You are given an array consisting of n integers which denote the position of a stall.You are also given an integer k which denotes the number of aggressive cows.You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
using namespace std;
/**
 * Determines if it is possible to place cows in stalls with a certain distance between them.
 *
 * @param stalls The vector of integers representing the stalls.
 * @param dis The distance between the stalls.
 * @param cows The number of cows to be placed.
 *
 * @return True if it is possible to place the cows, False otherwise.
 */
bool isPossiblePlace(vector<int> &stalls, int dis, int cows)
{
    int n = stalls.size();
    int last = 0;
    int placed = 1;
    for (int i = 0; i < n; i++)
    {
        if (stalls[i] - stalls[last] >= dis)
        {
            last = i;
            placed++;
            if (placed == cows)
                return true;
        }
    }
    return false;
}
/**
 * Solves the problem
 *
 * @param n the number of stalls
 * @param k the minimum distance between any two cows
 * @param stalls the vector of stalls
 *
 * @return the maximum number of cows that can be placed in the stalls
 *
 * @throws ErrorType description of error
 */
int solve(int n, int k, vector<int> &stalls)
{
    // we can start checking from  1 as minimum distance to (min - max) between any two cows, so
    // the max number in which will in which we will be able to place all cows will the the answer
    sort(stalls.begin(), stalls.end());
    int min_num = stalls[0];
    int max_num = stalls[n - 1];
    int ans = 1;

    /****
     // for(int i = 1; i<=(max_num - min_num); i++){
     //     if(isPossiblePlace(stalls, i, k)){
     //         continue;
     //     }
     //     else{
     //         return i-1;
     //     }
     // }
     //above approach would give quadratic time complexity
     // we can apply binary search instead
     ****/

    int start = 1;
    int end = max_num - min_num;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isPossiblePlace(stalls, mid, k))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int n = 5, k = 3;
    vector<int> stalls = {10, 1, 2, 7, 5};
    cout << solve(n, k, stalls);
    return 0;
}