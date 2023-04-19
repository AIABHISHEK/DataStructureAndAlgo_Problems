#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
int solve(vector<int> arr, int k){

    int sum = 0;
    int maxLen = 0;
    map<int, int> preSumMap;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i + 1);
        }
        if(preSumMap.find(sum - k) != preSumMap.end()){
            maxLen = max({maxLen, i - preSumMap[sum-k]});
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
        
    }
    return maxLen;
    //optimal approach
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<int> a = {1,2,0,3, 0, 0,1,1,1,-5,5,6};
cout<<solve(a, 6);
return 0;
}