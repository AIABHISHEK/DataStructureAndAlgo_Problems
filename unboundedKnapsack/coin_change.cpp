#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;


// coin change problem


//we to find the number of ways we get sum of coin == sum 
int solve_top_down(int coin[], int length, int sum) //length -> length of the coin array
{
    int dp[length + 1][sum + 1];
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = 0; // if sum is nonzero but length of coin array is zero
    }
    for (int i = 0; i <= length; i++){
        dp[i][0] = 1; //if sum is zero
    }


    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];

        cout << dp[i][j] << "   ";
        }
        
    }
    return dp[length][sum];
}


int main() {
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int t;
// cin >> t; 
int coin[] = { 1, 2, 3 };
int sum = 5;

cout << solve_top_down(coin, 3, sum);
return 0;
}