#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int removeDuplicates(vector<int> &nums)
{

    set<int> s;
    int i = 0;
    while (i < nums.size())
    {
        s.insert(nums[i]);
        i++;
    }
    int j = 0;
    int k = s.size();
    for (auto it = s.begin(); j < k;)
    {
        nums[j] = (*it);
        it++;
        j++;
    }
    for (auto i : nums)
    {
        cout << i << " ";
    }
    
    return k;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

// int arr[] = {1, 1, 2, 3};
vector<int> v = {1, 1, 2, 3};
cout << removeDuplicates(v);
return 0;
}