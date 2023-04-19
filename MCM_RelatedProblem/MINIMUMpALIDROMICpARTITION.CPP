#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

bool isPalindrome(string s, int i, int j)
{

    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j)
{
    // base condition if i >= j
    //  s is palidrome
    if (i >= j)
    {
        return 0;
    }
    else if (isPalindrome(s, i, j))
    {
        return 0;
    }
    long m = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        long ans = 1 + solve(s, i, k) + solve(s, k + 1, j);
        m = min(m, ans);
    }
    return m;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    string t;
    cin >> t;
    cout << solve(t, 0, t.length() - 1);
    return 0;
}