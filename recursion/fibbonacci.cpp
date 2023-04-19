#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
void printSubsequence(vector<int>& arr, vector<int>& ans, int i, int n){
    if(i == n){
        for (auto it : ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    
    printSubsequence(arr, ans, i+1, n);
    ans.push_back(arr[i]);
    printSubsequence(arr, ans, i+1, n);
    ans.pop_back();
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<int> arr = {1, 2, 3};
vector<int> a;
printSubsequence(arr, a, 0, 3);

return 0;
}