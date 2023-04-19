#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// minimum number of the deletion to make a string palindrome
//  to find the minimum number of the deletion find length of lps longest palindromic subsequence
// ans = string length - lps length

int solve(string a)
{
    string b = string(a.rbegin(), a.rend());

    // now find lcs of a and b
    vector<vector<int>> v(a.length() + 1, vector<int>(a.length() + 1));
    for (int i = 0; i <= a.length(); i++)
    {
        v[i][0] = 0;
        v[0][i] = 0;
    }

    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= a.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                v[i][j] = 1 + v[i - 1][j];
            }
            else
            {
                v[i][j] = max(v[i][j - 1], v[i - 1][j]);
            }
        }
    }
    return a.length() - v[a.length()][a.length()];
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    string a;
    cin >> a;
    cout << solve(a);

    return 0;
}