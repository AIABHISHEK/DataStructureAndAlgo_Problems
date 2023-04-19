#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void permutate(vector<int> arr, vector<vector<int>> &p, int i){
    if(i >= arr.size()){
        p.push_back(arr);
        return;
    }
    for (int j = i; j < arr.size(); j++){
        swap(arr[i], arr[j]);
        permutate(arr, p, i + 1);
        swap(arr[i], arr[j]);
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio


vector<int> arr = {1, 9, 3, 2};
// sort(arr.begin(), arr.end());
vector<vector<int>> p;
vector<bool> t(arr.size(), false);
vector<int> v;
permutate(arr, p, 0);
for (auto it : p)
{
    for (auto i : it)
    {
        cout << i << " ";
    }
    cout << endl;
}

return 0;
}