#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
// An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively,
//     such that : s = s1 + s2 + ... + sn 
//     t = t1 + t2 + ... + tm | n - m | <= 1 
//The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ... Note : a + b is the concatenation of strings a and b.


/**
 * Checks if a given string `s3` can be formed by interleaving the characters of strings `s1` and `s2`.
 *
 * @param s1 The first input string.
 * @param s2 The second input string.
 * @param s3 The target string to be formed.
 * @param i The current index in `s1`.
 * @param j The current index in `s2`.
 * @param k The current index in `s3`.
 * @param dp A 3D vector representing the memoization table for dynamic programming.
 *
 * @return `true` if `s3` can be formed by interleaving `s1` and `s2`, `false` otherwise.
 *
 * @throws None.
 */
bool solve(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>> &dp){
    if (k == s3.size())
        return true;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    if (s1[i] == s3[k] && s2[j] == s3[k])
    {
        return dp[i][j][k] = solve(s1, s2, s3, i + 1, j, k + 1, dp) || solve(s1, s2, s3, i, j + 1, k + 1, dp);
    }
    if (i < s1.size() && s1[i] == s3[k])
    {
        return dp[i][j][k] = solve(s1, s2, s3, i + 1, j, k + 1, dp);
    }
    else if (j < s2.size() && s2[j] == s3[k])
    {
        return dp[i][j][k] = solve(s1, s2, s3, i, j + 1, k + 1, dp);
    }
    return dp[i][j][k] = false;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    string s1 = "hello";
    string s2 = "world";
    string s3 = "wheorldllo";
    int i = 0;
    int j = 0;
    int k = 0;
    int n = s3.size();
    vector<int> alph(26, 0);
    for (auto ch : s1)
        alph[ch - 'a']++;
    for (auto ch : s2)
        alph[ch - 'a']++;
    for (auto ch : s3)
    {
        alph[ch - 'a']--;
    }
    for (auto it : alph)
        if (it)
            return false;
    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 2, -1)));
    cout<<solve(s1, s2, s3, i, j, k, dp);
    return 0;
}