#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// minimum number of insertion and deletion on string a to convert it to to b
// problem is similar to lcs first fnd the lcs and that twould bw common in the both string now remove the the ///
//charcter in a which are not part of the lcsand the add the the charcter which are in b but not part of the lcs

int solve(string a, string b, int la, int lb) {
    vector<vector<int>> vec(la + 1, vector<int>(lb + 1));
    for (int i = 0; i <= la; i++)
    {
        vec[i][0] = 0;
    }
    for (int i = 0; i <= lb; i++)
    {
        vec[0][i] = 0;
    }


    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            if (a[i - 1] == b[j - 1]) {
                vec[i][j] = 1 + vec[i - 1][j - 1]; 
            }
            else {
                vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
            }
        }
        
    }
    return (la + lb - 2*vec[la][lb]);
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
string a, b;
cin >> a >> b;

cout << solve(a, b, a.length(), b.length());

return 0;
}