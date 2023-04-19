#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

/**
 * @brief we will the permutation of array
 * 
 * @param arr the array whose permutation we have to find
 * @param v temporary vector to store the one pernutation
 * @param p final 2d array to store all permutations
 * @param t bool array which will set to true or if certain index element is taken or not
 */
void permutate(vector<int> arr ,vector<int> v, vector<vector<int>> &p, vector<bool>t){
    if(v.size() == arr.size()){
        p.push_back(v);
        return;
    }

    for (int i = 0; i < arr.size(); i++){
        if(!t[i]){
            t[i] = true;
            v.push_back(arr[i]);
            permutate(arr, v, p, t);
            v.pop_back();
            t[i] = false;
        }
    }
}


int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio


vector<int> arr = {1, 9, 3, 2};
// sort(arr.begin(), arr.end());
vector<vector<int>> p;
vector<bool> t(arr.size(),false);
vector<int> v;
permutate(arr, v, p, t);
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