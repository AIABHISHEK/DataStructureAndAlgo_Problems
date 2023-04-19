#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// vector<vector<int>> 
void generate(int numRows)
{
    vector<vector<int>> nums;
    for (int i = 0; i < numRows; i++){
        vector<int> v(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            v[j] = nums[i - 1][j] + nums[i - 1][j - 1];
        }
        nums.push_back(v);
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    // return nums;
}

int main(){
// ios_base::sync_with_stdio(false); // fastio
// cin.tie(NULL); // fastio

// vector<vector<int>> v = {{1, 2}, {1}};

// vector<vector<int>> v = 
generate(4);

// for (int i = 0; i < v.size(); i++)
// {
//     for (int j = 0; j < v[i].size(); j++)
//     {
//         cout << j << " ";
//     }
//     cout << endl;
// }
return 0;
}