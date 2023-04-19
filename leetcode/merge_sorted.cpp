#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> v1;
    vector<int> v2;
    int i = 0;
    int nums_l = nums.size();
    while (nums[i] < 0 && i < nums_l){
        cout << i << endl;
        v1.push_back(-1 * nums[i]);
        i++;
    }
    // cout << i <<endl;
    while (i < nums_l){
        cout << i <<endl;
        v2.push_back(nums[i]);
        i++;
    }
    
    int v1_l = v1.size();
    int v2_l = v2.size();

    nums.clear();

    int j = 0;
    cout << " v1_l" << v1_l;
    i = v1_l - 1;
    // cout << j << " " << v2_l << endl;
    while (i >= 0 && j < v2_l)
    {
        if (v1[i] <= v2[j])
        {
            nums.push_back(v1[i]);
            i--;
        }
        else if (v1[i] > v2[j])
        {
            nums.push_back(v2[j]);
            j++;
        }
    }
    while (i >= 0){
        nums.push_back(v1[i]);
        i--;
    }
    while (j < v2_l){
        nums.push_back(v2[j]);
        j++;
    }
    cout <<"fghj"<< nums_l;
    for (i = 0; i < nums_l; i++){
        int t = nums[i];
        nums[i] = t * t;
    }
    return nums;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    // int t;
    // cin >> t;
    vector<int> ar = {-4, -3, -2, -1};
    //
    vector<int> v = sortedSquares(ar);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}