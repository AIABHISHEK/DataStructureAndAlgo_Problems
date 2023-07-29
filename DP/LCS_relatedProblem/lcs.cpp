#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

/// lcs -->>  longest common subsequence


int solve(string a, string b, int la, int lb) { //la ->length of string a, lb ->length of string b
    if (la == 0 || lb == 0)
        return 0; // when either of string is empty, return 0;

    if (a[la - 1] == b[lb - 1]) {
        // use pop_back() to remove last character of string
        // use erase(pos, len) to remove last character
        // erase(a.length() - 1, 1);
        //substr()   -> a.substr(start, length)
        //resize -> removes charcter from end and returns the string of length passed in the argument 
        return 1 + solve(a, b, la - 1, lb - 1);
    }

    else {
        return max(solve(a, b, la, lb - 1), solve(a, b, la - 1, lb));
    }
}

// recursive memoized 
int dp[20][20]; //
int solve_recursive(string a, string b, int la, int lb) {

    if (la == 0 || lb == 0)
        return 0; //

    if (dp[la][lb] > -1)
        return dp[la][lb]; // solved for given la and lb so return that

    if (a[la - 1] == b[lb - 1]) {
        return dp[la][lb] = (1 + solve(a, b, la - 1, lb - 1)); //
    }
    else {
        return dp[la][lb] = max(solve(a, b, la, lb - 1), solve(a, b, la - 1, lb));
    }
}

int solve_recursive(string a, string b) {
    int la = a.length();
    int lb = b.length();
    memset(dp, -1, sizeof(dp));
    return solve_recursive(a, b, la, lb);
}


// top down 

int solve_top_down(string a, string b, int la, int lb) {

    int t[la + 1][lb + 1];
    for (int i = 0; i <= la; i++)
    {
        t[i][0] = 0;
    }
    for (int i = 0; i <= lb; i++)
    {
        t[0][i] = 0;
    }

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {

            if (a[i - 1] == b[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    return t[la][lb];
}

int main() {
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL); // fastio
    int t;
    // cin >> t; 
    string a, b;
    cin >> a >> b;
    // cout << a.erase(a.length() - 1);
    // a.pop_back();
    cout << solve(a, b, a.length(), b.length()) << endl;
    cout << solve_recursive(a, b) << endl;
    cout << solve_top_down(a, b, a.length(), b.length());
    return 0;
}