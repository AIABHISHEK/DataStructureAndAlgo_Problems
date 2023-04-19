#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

bool targetSum(vector<int> arr, int i, int sum, int target, vector<int>& ans){
    if(i >= arr.size()){
        if(sum == target){
            for (auto it : ans)
            {
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        else{
            return false;
        }
    }
    sum += arr[i];
    ans.push_back(arr[i]);
    if(targetSum(arr, i+1, sum, target, ans))
        return true;
    ans.pop_back();
    sum -= arr[i];
    if(targetSum(arr, i+1, sum, target, ans))
        return true;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

vector<int> arr = {3, 1, 2};
vector<int> v;

cout<<targetSum(arr, 0, 0, 4, v);
return 0;
}