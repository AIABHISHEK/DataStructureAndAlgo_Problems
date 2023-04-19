#include <bits/stdc++.h>

#define ll unsigned long int
#define int_ unsigned int

using namespace std;

// problem
//  You are given an array  consisting of  non-negative integers. Find out the minimum number k such that there exists a non-empty subset of A  for which the bitwise OR of all its elements is equal to k.
//  The bitwise OR of two numbers is just the sum of those two numbers if there is no carry involved, otherwise you just add their bitwise AND
int solve(ll A[], int n)
{
    ll min = ULONG_MAX;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

int main()

{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    cin >> t;
    vector<int> v; // no of test cases
    while (t--)
    {
        ll n;
        // no of element in the  array
        cin >> n;
        ll A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        v.push_back(solve(A, n));
    }
    // cout << (t | r);
    for (auto i : v)
    {
        cout << i << endl;
    }
    
    return 0;
}