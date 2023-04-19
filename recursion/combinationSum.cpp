#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void sum(vector<int> v, vector<int> arr, int l, int target){
    cout << "A ";
    if(target == 0){
        cout << l  << " - >  ";
        for (auto i : v){
            cout << i << " ";
        }
        cout << endl;
        return;
        }
        if(target < 0)
        return;
        if(l == arr.size()){
        return;
        }
        
        if (arr[l] <= target)
        {
            v.push_back(arr[l]);
            sum(v, arr, l, target - arr[l]);
            v.pop_back();
        }
        
        sum(v, arr, l + 1, target);
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int t;
cin >> t;
vector<int> arr = {3, 2, 1 ,4};
vector<int> v;
sum(v, arr, 0, t);
return 0;
}