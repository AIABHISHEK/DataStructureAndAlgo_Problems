#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

// NINJA TRAINING PROBLEM  ************************************************** code-studio


using namespace std;
int solve(vector<vector<int>>& m, int day, int last, vector<vector<int>>& dp){
    
    if(day == 0){
        int maxPoint = INT_MIN;
        for(int i = 0; i<3; i++){
            if(i == last) continue;
            maxPoint = max(maxPoint, m[day][i]);
        }
        return maxPoint;
    }
    if(dp[day][last] != -1)
        return dp[day][last];

    int maxPoint = INT_MIN;
    for(int i = 0; i<3; i++){
            if(i == last) continue;
            maxPoint = max(maxPoint, solve(m, day-1, i, dp) + m[day][i]);
        }
    return dp[day][last] = maxPoint;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

// 2 d arry of size 5 x 3;
vector<vector<int>> m =  {{1,2,3},
                    {3, 4, 2},
                    {4, 1,2},
                    {3, 1,6},
                    {9, 3, 1}};

vector<vector<int>> dp(5, vector<int>(4, -1));
    // cout<<solve(m, 4, 3, dp);
    





    // tabulation solution
    // base case initialization
    dp[0][0] = max(m[0][1], m[0][2]);
    dp[0][1] = max(m[0][0], m[0][2]);
    dp[0][2] = max(m[0][1], m[0][0]);
    //case no prev training
    dp[0][3] = max({m[0][1], m[0][2], m[0][0]});

    // for loop for days
    for(int day = 1; day<5; day++){
        // loops for tasks
        for(int last = 0; last<4; last++){
            int maxPoint = INT_MIN;
            for(int task = 0; task<3; task++){
                if(task == last) continue;
                maxPoint = max(maxPoint, dp[day-1][last]+m[day][task]);
            }
            dp[day][last] = maxPoint;
        }
    }

    // cout<<dp[4][3];



    /// space optimization 
    // since for each day calculation  we only need last day(row) so we can optimize space 
    vector<int> prev(4, -1);
     prev[0] = max(m[0][1], m[0][2]);
    prev[1] = max(m[0][0], m[0][2]);
    prev[2] = max(m[0][1], m[0][0]);
    //case no prev training
    prev[3] = max({m[0][1], m[0][2], m[0][0]});
    for(int day = 1; day<5; day++){
        // loops for tasks
        // we will calculate this vector with help of above prev and this will became next prev
        vector<int> temp;
        for(int last = 0; last<4; last++){
            int maxPoint = INT_MIN;
            for(int task = 0; task<3; task++){
                if(task == last) continue;
                maxPoint = max(maxPoint, prev[last] + m[day][task]);
            }
            temp.push_back(maxPoint);
        }
        prev = temp;
    }
    cout<<prev[3];
return 0;
}