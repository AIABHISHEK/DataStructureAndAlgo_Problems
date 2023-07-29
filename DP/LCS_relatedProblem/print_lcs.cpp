#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

//print the lcs 
using namespace std;

string solve(string a, string b, int la, int lb) {

    int t[la + 1][lb + 1]; //

    for (int i = 0; i <= la; i++) {
        t[i][0] = 0;
    }
    for (int i = 0; i <= lb; i++) {
        t[0][i] = 0;
    }
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            if (a[i] == b[j]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    cout << t[la][lb] << endl;
    string s;
    int i = la, j = lb;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            s.push_back(a[i - 1]);
            i--;
            j--;
        }
        else {
            if (t[i - 1][j] > t[i][j - 1]) 
                i--;
            else 
                j--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL); // fastio
    int t;
    // cin >> t;
    string a, b;
    cin >> a >> b;
    cout << solve(a, b, a.length(), b.length());
    return 0;
}