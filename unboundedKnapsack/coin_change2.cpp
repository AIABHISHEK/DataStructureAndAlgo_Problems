#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// coin change problem 
//we have too find minimum number of coins that have sum equal to given sum

int solve(int coin[], int length, int sum) {
    int dp[length + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
    {
        // dp[0][i] = INT_MAX - 1;
        dp[0][i] = sum + 1; //number of coins will always less than sum
    }
    for (int i = 0; i <= length; i++)
    {
        dp[i][0] = 0;
    }
    // but above two initialization will not give answer
    // we initialize one more array (1st index row)

    
// for (int i = 1; i <= sum; i++)  //initialize when coin array length is 1
// {
//     if (i % coin[0] == 0)
//         dp[1][i] = (i / coin[0]);
//     else
//         dp[1][i] = INT_MAX - 1;// ex 4/3 not possible to assign the number of 3 vlaued coin to get sum 4 so put max number
    
//     cout << dp[1][i] << " ";
// }

    
    cout << endl;
    
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= sum; j++) {
            if (coin[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
            cout << dp[i][j] << " ";
        }
    }
    cout << endl;
    return dp[length][sum] > sum ? -1 : dp[length][sum];
}
    int main() {
        ios_base::sync_with_stdio(false); // fastio
        cin.tie(NULL); // fastio
        int t;
        // cin >> t;
        int coin[] = { 6, 5, 3 };
        int sum = 7;

        cout << solve(coin, 3, sum);

        return 0;
    }