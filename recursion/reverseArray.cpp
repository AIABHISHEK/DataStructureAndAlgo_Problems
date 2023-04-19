#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void reverse_arr(vector<int>& arr, int start, int end){
    if(start == end)
        return; //
    swap(arr[start], arr[end]);
    // int temp = arr[start];
    // arr[start] = arr[end];
    // arr[end] = temp;
    reverse_arr(arr, start+1, end-1);
}

void reverse(int arr[], int start, int end){
    if(start == end)
        return; //
    swap(arr[start], arr[end]);
    reverse(arr, start+1, end-1);
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

    vector<int> arr = {1, 2, 3, 4, 5};
    reverse_arr(arr, 0, 4);
    int ar[] = {9, 8, 7, 6, 5};
    reverse(ar, 0, 4);
    for (auto i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for (auto i : ar)
    {
        cout<<i<<" ";
    }
    

return 0;
}