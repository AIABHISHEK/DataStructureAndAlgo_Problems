#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// print shortest common supersequence
//  problem is similar to print lcs but here we need print to common char once along char which are not common

string solve(string a, string b, int la, int lb)
{
    vector<vector<int>> v(la + 1, vector<int>(lb + 1));
    for (int i = 0; i <= la; i++)
    {
        v[i][0] = 0;
        v[0][i] = 0;
    }
    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                v[i][j] = 1 + v[i - 1][j - 1];
            }
            else
            {
                v[i][j] = max(v[i][j - 1], v[i - 1][j]);
            }
        }
    }
    int i = la, j = lb;
    string s;
    while (i > 0 && j > 0)
    {
        if(a[i - 1] == b[j - 1])
        {
            s.push_back(a[i - 1]);
            i--;
            j--;
        }
        else{
            if(v[i][j - 1] > v[i - 1][j]){
                s.push_back(b[j - 1]);
                j--;
            }
            else{
                s.push_back(a[i - 1]);
                i--;
            }
        }
    }
    while(i > 0)
    {
        s.push_back(a[i - 1]);
        i--;
    }
    while(j > 0)
    {
        s.push_back(b[j - 1]);
        j--;
    }
    s = string(s.rbegin(), s.rend());
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    string a, b;
    cin >> a >> b;
    cout << solve(a, b, a.length(), b.length());
    return 0;
}