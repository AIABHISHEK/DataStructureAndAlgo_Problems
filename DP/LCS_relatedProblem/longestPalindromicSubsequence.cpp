#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// longest palindromic subsequence
//given a string we have find length of longest subsequence such that it is palindromic 
// to solve problem revers the given string and assign it another string now find the length of lcs of the string

                    /********************************************/
// reverse_copy(a.begin(), a.end(), b.begin()); // it throw error beacuse b is emty it not be resized
//  to ensure correct output b.resize(a.size());
// or we can use reverse_copy(a.begin(), a.end(), back_inserter(b));
// use string b = string(a.rbegin(), a.rend());
// use reverse function ,  b = a; then reverse a reverse(a.begin(), a.end());

int solve(string a){

    string b;
    b = string(a.rbegin(), a.rend());

    vector<vector<int>> v(a.length() + 1, vector<int>(a.length() + 1));

    for (int i = 0; i < a.length(); i++)
    {
        v[i][0] = 0;
        v[0][i] = 0;
    }

    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= a.length(); j++)
        {
            if(a[i - 1] == b[j - 1])
                v[i][j] = 1 + v[i - 1][j - 1];
            else
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
        }
        
    }
    return v[a.length()][a.length()];
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
string a;
cin >> a;
cout << solve(a);

return 0;
}