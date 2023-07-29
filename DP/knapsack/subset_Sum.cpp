#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// Given a array and sum find if a subset present  whose sum of elements is equal to given  sum


// recurssive
bool solve(int a[], int length, int sum)
{
    // base condition
    if (sum == 0)
        return true;
    else if (length == 0)
        return false;//length is zero means no subset found 

    if (a[length - 1] <= sum)
        return solve(a, length - 1, sum - a[length - 1]) || solve(a, length - 1, sum);  
        // if number is less than sum either select it or not 
    else
        return solve(a, length - 1, sum);
        
}


// dp  recurssive

int dp[100][100]; // array for memoi
bool solve_dp(int a[], int length, int sum){
    if(sum == 0)
        return 1; //true
    else if (length == 0)
        return 0; // false
    if(dp[length][sum] > -1)
        return dp[length][sum];

    if(a[length - 1] <= sum){
        return dp[length][sum] = solve_dp(a, length - 1, sum - a[length - 1])||solve_dp(a, length - 1, sum);
    }
    else{
        return dp[length][sum] = solve_dp(a, length - 1, sum);
    }    
    
}

bool dp_(int a[], int length, int sum){
    memset(dp, -1, sizeof(dp));
    return solve_dp(a, length, sum);
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    cin >> t;
    return 0;
}