#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
//upper bound --> number which is just greater than x

/**
 * Finds the upper bound of a given element in a sorted vector.
 *
 * @param v the vector of integers
 * @param x the element to find the upper bound for
 *
 * @return the element that is just greater than x, or -1 if x is greater than any element in the vector
 *
 * @throws None
 */
/**
 * Finds the upper bound of a given element in a sorted vector.
 *
 * @param v the vector of integers
 * @param x the element to find the upper bound for
 *
 * @return the element that is just greater than x, or -1 if x is greater than any element in the vector
 *
 * @throws None
 */
int upper_bound(vector<int> v, int x){
    int ans = v.size();
if(ans == 0) throw range_error("vector is empty"); // if vector is empty then return -1
    int start = 0;
    int end = v.size()-1;
    int mid;
    while (start <= end){
        mid = start + (end-start)/2;
        if(v[mid] > x){
            ans = mid;
            end = mid - 1; // if v[mid] > x then we need to find the number which is just greater than x so we need to move to left side
        }
        else{
            start = mid + 1; // if v[mid] <= x then we need to find the number which is just greater than x so we need to move to right side
        }
    }
    return ans>=v.size()?-1:v[ans];
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<int> v = {3, 5, 8, 15, 19};
// vector<int> v = {};
// test cases 
cout<<upper_bound(v, 8)<<endl;
cout<<upper_bound(v, 9)<<endl;
cout<<upper_bound(v, 1)<<endl;
cout<<upper_bound(v, 19)<<endl;
cout<<upper_bound(v, 20)<<endl;

return 0;
}