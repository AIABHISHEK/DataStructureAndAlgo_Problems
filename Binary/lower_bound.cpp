#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int lower_bound(vector<int> v, int x){

    int start = 0;
    int end = v.size()-1;
    int mid;
    // while(start <= end){
    //     mid = start + (end-start)/2;
    //     if(v[mid] == x) return v[mid];
    //     else if(v[mid] > x){
    //         end = mid-1;
    //     }
    //     else{
    //         start = mid + 1;
    //     }
    // }
    int ans = v.size(); // if not found any number which is greater than or equal to x then then return size() of vector
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (v[mid] >= x){
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    // cout << mid << " " << start << " " << end << endl;
    return ans>=v.size()?-1:v[ans];
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<int> v = {3, 5, 8, 15, 19};
cout << lower_bound(v, 8) << endl;
cout << lower_bound(v, 9) << endl;
cout << lower_bound(v, 1) << endl;
cout << lower_bound(v, 19) << endl;
cout << lower_bound(v, 20) << endl;

return 0;
}