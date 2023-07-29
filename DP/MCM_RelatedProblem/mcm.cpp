#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
int solve(int arr[], int i, int j){

    if (i >= j){
        return 0;
    }
// CHANGE
    int m = INT_MAX;
    for (int k = i; k <= j - 1; k++){
        int sum1 = solve(arr, i, k);
        int sum2 = solve(arr, k + 1, j);
        int sum3 = arr[i - 1] * arr[k] * arr[j];
        int sum = sum1 + sum2 + sum3;
        m = min(m, sum);
    }
    return m; //CHANGE
}

int main(){
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int arr[] = {4, 5, 3, 2, 3};
    cout << solve(arr, 1, 4) << "  this is ans\n";
    return 0;
}