#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// given an array find all the unique combination whose sum is equal to target sum

void combination(vector<int> &arr, vector<vector<int>> &ans, vector<int> &v, int i, int target){
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(i >= arr.size()){
        return;
    }
    for (int j = i; j < arr.size(); j++){
        if(j > i && arr[j - 1] == arr[j]){
            continue;
        }
        if(arr[j] > target){
            break;
        }
        v.push_back(arr[j]);
        combination(arr, ans, v, j + 1, target - arr[j]);
        v.pop_back();
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int t;
cin >> t;
vector<int> arr = {2 ,3, 2, 1, 5, 1};
sort(arr.begin(), arr.end());
vector<vector<int>> ans;
vector<int> v;
combination(arr, ans, v, 0, t);
// cout << ans[0][0];
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