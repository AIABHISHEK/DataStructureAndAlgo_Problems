#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

//shortest common supersquence
// given two strings we have two merge them so that it conatain suequence of the two strings and we have to merge in such a way that it shortest and find its length
// solution of above prb is sum of length of the two strings - common subseuence of the two strings because we have to remove common while combining to get the shortest super subseuence.

int solve(string a, string b, int la, int lb) {

    int t[la + 1][lb + 1];

    for (int i = 0; i <= la; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 1; j <= lb; j++)
    {
        t[0][j] = 0;
    }

    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    return (la + lb - t[la][lb]);
}


int main() {
    
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL); // fastio
    string a, b;
    cin >> a >> b;
    cout << solve(a, b, a.length(), b.length());
    
    return 0;
}