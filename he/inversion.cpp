// #include<bits/stdc++.h>
#include<iostream>
#include<vector>


// #define ll long long int
// #define int_ unsigned int

using namespace std;

void solve(int a_i[], int r_i[], int n) {
    vector<int> v(n + 1, -1);
    int a[n];
    int r[n];
    // for array a
    for (int i = n - 1; i >= 0; i--) {
        int j = a_i[i];
        int l = n;
        
        if (j > i) {
            cout << -1 << endl;
            return;
        }
        while (j >= 0) {
            if (j == 0) {
                if (v[l] == -1)
                    break;
                l--;
            }
            else {
                if (v[l] == -1)
                
                {
                    j--;
                }
                l--;
            }
        }
        a[i] = l;
        v[l] = 0;
    }
    for (int p = 0; p < n; p++) {
        cout << a[p] << " ";
    }
    fill(v.begin(), v.end(), -1);

    for (int i = n - 1; i >= 0; i--) {
        int j = r_i[i];
        int l = n;
        
        if (j > i) {
            cout << -1 << endl;
            return;
        }
        
        while (j >= 0) {
            
            if (l == 0) {
                cout << -1 << endl;;
                return;
            }
            if (j == 0) {
                if (v[l] == -1)
                    break;
                l--;
                
            }
            else {
                if (v[l] == -1)
                {
                    j--;
                }
                l--;
            }
        }
        cout <<" l is "<< l << endl;
        r[i] = l;
        v[l] = 0;
    }
    // for (int p = 0; p < n; p++) {
    //     cout << r[p] << " ";
    // }
    // for (int i = 0, j = n-1; i < n && j>=0; i++, j--)
    // {
    //     if (a[i] != r[j])
    //         cout << -1 << endl;
    //     return;
    // }
    for (int p = 0; p < n; p++) {
        cout << r[p] << " ";
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL); // fastio
    int t;
    cin >> t;
    while (t) {
        int n;
        cin >> n;
        int a_i[n];
        int b_i[n];
        for (int i = 0; i < n; i++) {
            cin >> a_i[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b_i[i];
        }
        solve(a_i, b_i, n);
        t--;
    }
    return 0;
}