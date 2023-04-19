#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// problem -- 

 // https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/make-it-non-decreasing-7d3391fd/

void solve(ll A[], ll n){
    vector<ll> v(n);
    v[0] = A[0];

    for (int i = 1; i < n; i++)
    {
        // if A_i > write that no in v_i as this satisfy condition
        if (v[i - 1] <= A[i]){ 
            v[i] = A[i];
        }
        else{
            if ((v[i - 1]&A[i]) == 0)
            {
                v[i] = v[i - 1];
            }
            else {
                ll q = v[i - 1] / A[i];
                v[i] = (q+1) * A[i];
            }
        }
    }
    // cout << (v.size());
    for (auto i : v)
    {
        cout << i;
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

ll t, n;

cin >> t; 
while(t--){
    cin >> n;
    ll A[n];
    for (ll i = 0; i <n; i++){
        cin >> A[i];
    }
    solve(A, n);
    // cout<<(v.size());
}
return 0;
}