#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
//Problem Statement find longest increasing subsequence

/**
 * Calculates the length of the longest increasing subsequence in a given array.
 *
 * @param arr the array of integers
 * @param n the size of the array
 *
 * @return the length of the longest increasing subsequence
 *
 * @throws None
 */
int lis(vector<int> arr, int n){
    vector<int> dp(n, 1);
    dp[0] = 1;
    int ans = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return ans;
}
/**
 * Calculates the Longest Increasing Subsequence (LIS) of the given array.
 *
 * @param arr the array of integers
 * @param n the size of the array
 *
 * @throws None
 */
void printLIS(vector<int> arr, int n){
    vector<int> dp(n, 1);
    vector<int> index(n, 1);
    //index stores the prev index of the element which was added to the current DP array in its position.
    for (int i = 0; i < n; i++)
    {
        index[i] = i;
    }
    // fill the index with their own index beacuse currently they stores their own value at index
    int ans = 1; // now at answer store the index of 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    index[i] = j; // stores the index which was added to the current DP array
                }
                if(dp[ans] < dp[i]){
                    ans = i;
                }
            }
        }
    }
    int i = ans;
    cout << endl;
    while(i >= 0){
        cout<<arr[i]<<" ";
        if(i == index[i]) // break when it is last index
            break;
        i = index[i];
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
//test case for lIS
// lis({10, 22, 9, 33, 21, 50, 41, 60}, 7);
cout<<lis({10, 22, 9, 33, 21, 50, 41, 60}, 8); // output of LIS length 5
printLIS({10, 22, 9, 33, 21, 50, 41, 60}, 8); // the output of printLIS {10, 22, 33, 50, 60}

return 0;
}