#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;


// longest repeating subsequence 
// given a string we have find subsequence but same subsequence should also we  ]present after removing the first subsequence 
// ex- string a = aabfgcftxhx
// subsequence afx at index 0, 3, 8
// same afx is at index 1, 6, 10

// so we can see character which are present more than once are part of subsequnce 
// so if we make duplicate of string and find subsequnce of 2 string such that the charcter do not belong to the same index 
// that will give us the answer 

int solve(string a){
    string ss;
    int la = a.length();
    string b ;
    
    vector<vector<int>> v(la + 1, vector<int>(la + 1));
    for (int i = 0; i <= la; i++)
    {
        v[i][0] = 0;
        v[0][i] = 0;
    }
    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= la; j++)
        {
            if(a[i - 1] == a[j - 1] && i != j){
                v[i][j] = 1 + v[i - 1][j - 1];
            }
            else{
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
            cout << v[i][j]<<" , ";
        }
        cout << endl;
    }
    return v[la][la];
}

bool func(){
    return  true;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
string a;
cin >> a;
cout << solve(a);
return 0;
}