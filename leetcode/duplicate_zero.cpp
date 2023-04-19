#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void duplicateZeros(vector<int> &arr)
{
    int l = arr.size();
    vector<int> an(l, 0);
    int i = 0;
    int j = 0;
    while (j < l)
    {
        if (arr[i] != 0)
        {
            an[j] = arr[i];
            i++;
            j++;
        }
        else if (arr[i] == 0)
        {
            i++;
            j += 2;
        }
    }
    for (int k = 0; k < l; k++)
    {
        arr[k] = an[k];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    // int t;
    // cin >> t;

    vector<int> v = {6, 7, 0, 9};
    duplicateZeros(v);
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}