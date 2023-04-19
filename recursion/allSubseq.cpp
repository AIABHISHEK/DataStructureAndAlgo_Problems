#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void printSequence(vector<int>& v, vector<int> arr, int i){
    if(i>=arr.size()){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    else{
        printSequence(v, arr, i + 1);
        v.push_back(arr[i]);
        printSequence(v, arr, i + 1);
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
// int t;
// cin >> t;
vector<int> arr = {3, 1, 2};
vector<int> v;
printSequence(v, arr, 0);

return 0;
}