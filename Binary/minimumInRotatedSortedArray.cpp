#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
/**
 * Binary searches for the smallest element in a given vector.
 *
 * @param v the vector to search in
 *
 * @return the index of the smallest element in the vector
 *
 * @throws None
 */
int search(vector<int>v){
    int start= 0;
    int end = v.size()-1;
    int mid;
    int ans = -1;
    while(start<=end){
        mid = start + (end - start) / 2;
        //if array is sorted from mid to end then smallest element will somewhere at mid to start
        if(v[mid] <= v[end]){
            if(ans == -1 || v[ans] > v[mid])
                ans = mid;
            end = mid - 1;
        }
        /**
         * @brief if array is not sorted from mid to end then smallest element will be somewhere at mid+1 to end
         * 
         */
        // array not sorted from mid to  end
        // else if(v[mid] > v[end]){
        //     start = mid + 1;
        // }
        // else if(v[mid] >= v[start]){
        //     start = mid + 1;
        // }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

//test cases
vector<int> v = {4, 5, 6, 7, 0, 1, 2};
// vector<int> v = {4, 5, 6, -1, 0, 1, 2};
// vector<int> v = {4, 5, 6, 7, 8, 9, 2};
// vector<int> v = {4, 5, 6, 7, 8, 9, 10};
// vector<int> v = {4, -1, 2, 3};
// vector<int> v = {3,1,2,3,3,3,3}; 
// vector<int> v = {3,3,2,3,3,3,3}; 
// vector<int> v = {3,3,3,3,3,3,3}; 
cout << search(v) << endl;
return 0;
}