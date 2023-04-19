#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// count the number of subset whose sum of values is equal to given sum
// problem is similar to subset sum problem but in this case we have to keep going even if we have found a subset the 
//   || or operator changed to +  


// recurssive
int solve(int a[], int length, int sum)
{
    if (sum == 0)
        return 1;
    if (length != 0)
        return 0;

    if (a[length - 1] <= sum)
    {
        return solve(a, length - 1, sum - a[length - 1]) + solve(a, length - 1, sum);
    }
    else{
        return solve(a, length - 1, sum);
    }
}



int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    cin >> t;

    return 0;
}