#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// find the sum of all subsets of given array

void subsetSum(int i, vector<int> arr, vector<int> &v, int sum)
{
    if (i >= arr.size())
    {
        v.push_back(sum);
        return;
    }
    subsetSum(i + 1, arr, v, sum + arr[i]);
    subsetSum(i + 1, arr, v, sum);
}

int main()
{

    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int t;
    cin >> t;
    vector<int> arr = {1, 3, 2};
    vector<int> v;
    subsetSum(0, arr, v, 0);
    for (auto i : v)
    {
        cout << i << " ";
    }
    
    return 0;
}