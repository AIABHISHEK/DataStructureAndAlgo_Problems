#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// find sequence of 3 s[i] < s[j] < s[k] and also i < j < k;

bool solve(vector<int> arr){
    int m = arr[0];
    for (int i = 0; i < arr.size() - 2; i++){
        if(arr[i]>m)
            continue;
        for (int j = i + 1; j < arr.size() - 1; j++){
            if(arr[i] >= arr[j])
                continue;
            for (int k = j + 1; k < arr.size(); k++){
                m = max(m, arr[k]);
                if(arr[k] > arr[j])
                    return true;
            }
        }
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio


return 0;
}