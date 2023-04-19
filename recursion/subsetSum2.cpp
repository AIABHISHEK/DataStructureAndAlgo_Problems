#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// find all the subsets with no duplicates
// brute force find all the subsets and removes duplictes can done using sets which which will take nlog(n) for n elements we have 2^m

void subsetSum(int i, vector<int> arr, vector<vector<int>> &ans, vector<int> &v){
    if(i != 0)
        ans.push_back(v);

    if(i >= arr.size())
        return;
    for (int j = i; j < arr.size(); j++){
        if(j > i && arr[j - 1] == arr[j])
        continue;
        v.push_back(arr[j]);
        subsetSum(j + 1, arr, ans, v);
        v.pop_back();
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

vector<int> arr = {1, 1, 1, 3, 2};
sort(arr.begin(), arr.end());
vector<vector<int>> ans;
vector<int> v;
subsetSum(0, arr, ans, v);
for (auto it : ans)
{
    for (auto i : it)
    {
        cout << i << " ";
    }
    cout << endl;
}

return 0;
}