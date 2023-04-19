#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// problem --https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-sum-0423b95e/

void solve(vector<ll> v, int n, int k)
{

    sort(v.begin(), v.end());
    if (v[n - 1] < 0)
    {
        cout << 0 << endl;
        return;
    }
    ll sum = 0;
    if (k >= n || k == 0)
    {
        cout << sum << endl;
        return;
    }
    else
    {
        int i = 1;
        int j = 0;
        while (j < k)
        {
            if (v[n - i] < 0)
            {
                break;
            }
            sum = sum + v[n - i];
            if (i == n)
                break;

            if (v[n - i] != v[n - i - 1])
            {
                j++;
            }
            i++;
        }
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        solve(v, n, k);
    }
    return 0;
}