#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// longest common sub-string

int solve(string a, string b, int la, int lb, int count) {
    int m = count;
    if (la <= 0 || lb <= 0)
        return count;

    if (a[la - 1] == b[lb - 1])
        m = solve(a, b, la - 1, lb - 1, count + 1);

    int n1 = solve(a, b, la, lb - 1, 0);
    int n2 = solve(a, b, la - 1, lb, 0);
    return max(m, max(n1, n2));

}

int solve_top_down(string a, string b, int la, int lb) {

    int t[la + 1][lb + 1];
    for (int i = 0; i <= la; i++) {
        t[i][0] = 0;
    }
    for (int i = 0; i <= lb; i++) {
        t[0][i] = 0;
    }
    int m = 0;
    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            if (a[i - 1] == b[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            }

            else {
                t[i][j] = 0;
            }
            m = max(m, t[i][j]);
        }

    }
    //print the value of the array t
    for (int i = 0; i <= la; i++) {
        for (int j = 0; j <= lb; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    
    return m;
}
int main() {
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL); // fastio
    int t;
    // cin >> t; 

    string a, b;
    cin >> a >> b;
    // cout << solve(a, b, a.length(), b.length(), 0);
    cout << solve_top_down(a, b, a.length(), b.length());
    return 0;
}