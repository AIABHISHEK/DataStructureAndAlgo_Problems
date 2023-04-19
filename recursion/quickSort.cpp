#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int placePivot(vector<int>& arr, int pivot, int low, int high){

    int pivotValue = arr[pivot];
    int i = low;
    int j = high;
    while(i<j){
        while(pivotValue >= arr[i] && i<high){
            i++;
        }
        while(pivotValue < arr[j] && j>low){
            j--;
        }
        if(i<j)
            swap(arr[i], arr[j]);
    }
    swap(arr[pivot], arr[j]);
    return j;
}

void qs(vector<int>& arr, int pivot, int low, int high){
    if(low < high){
        int pivotValue = arr[pivot];
        int index = placePivot(arr, pivot, low, high);
        qs(arr, low, low, index - 1);
        qs(arr,index+1, index+1, high);
    }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

vector<int> arr = {4, 3, 3, 3, 3, 3};
qs(arr, 0, 0, 5);
for (auto i : arr)
{
    cout<<i<<" ";
}

return 0;
}