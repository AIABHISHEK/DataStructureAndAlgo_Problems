#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int lis(vector<int> arr, int n)
{
    vector<int> dp1(n, 1);
    dp1[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        dp1[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
                ans = max(ans, dp1[i]);
            }
        }
    }
    //find the list from end of list
    vector<int> dp2(n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        dp2[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
                ans = max(ans, dp2[i]);
            }
        }
    }
    //now since we have dp1 and dp2 which stores the length of the longest increasing subsequence from start and end of the array respectively
    // so if we add the length of the longest increasing subsequence from end of the array to the length of the longest increasing subsequence from start of the array and subtract 1 from it we get the answer for that index i.e. longest bitonic subsequence for that index so we easily find the max bitonic subsequence
    int ans = 0;
    for (int i = 1; i < n-1; i++){
        if(dp1[i] != 1 && dp2[i] != 1)
            ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    return ans;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

return 0;
}