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
}

 //optimal approach
    // two pointer approach
    int solve_optimal(vector<int> arr, int k){
        int maxLen = 0;
        int sum = 0;
        int i = 0; 
        int j = 0;
        int n = arr.size();
        while(j<n){
            sum += arr[j];
            if(sum == k){
                maxLen = max(maxLen, j - i + 1);
            }
            while (sum > k && i<j){
                sum -= arr[i];
                i++; 
            }
            j++;
        }
        return maxLen;
    }
    // same solution (optimal)
    int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<int> a = {1,2,0,3, 0, 0,1,1,1,-5,5,6};
cout<<solve(a, 6)<<endl;
cout<<solve_optimal(a, 6)<<endl;
cout<<getLongestSubarray(a, 6);
return 0;
}