

#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// LINK: https://leetcode.com/problems/combinations

//  Given two integers n and k, return all possible combinations of k numbers chosen from the range[1, n].

/**
 * Generates all combinations of size k from numbers 1 to n.
 *
 * @param i the starting index for generating combinations
 * @param ans a reference to a vector to store the combinations
 * @param curr a vector to store the current combination
 * @param n the maximum number to consider for combinations
 * @param k the size of the combinations
 *
 * @return void
 *
 * @throws None
 */
void solve(int i, vector<int> &curr, vector<vector<int>> &ans, int k, int n)
{
    
    // {
    //     if (curr.size() == k)
    //     {
    //         ans.push_back(curr);
    //         return;
    //     }
    //     else
    //         return;
    // }
    if (curr.size() == k)
    {
        ans.push_back(curr);
        return;
    }
    if (i > n)
        return;
        curr.push_back(i);
    solve(i + 1, curr, ans, k, n);
    curr.pop_back();
    solve(i + 1, curr, ans, k, n);
}
void print(vector<vector<int>> &ans){
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int k = 2, n = 4;
// cin >> k >> n;
vector<vector<int>> ans;
vector<int> curr;
solve(1, curr, ans, k, n);
cout << ans.size();
print(ans);
// Input:
// n = 4, k = 2 
//Output : [ [ 1, 2 ], [ 1, 3 ], [ 1, 4 ], [ 2, 3 ], [ 2, 4 ], [ 3, 4 ] ]
return 0;
}
