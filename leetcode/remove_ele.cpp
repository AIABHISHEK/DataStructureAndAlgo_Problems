#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int removeElement(vector<int> &nums, int val){
    int i = 0;
    int j = nums.size() - 1;
    int l = 0;
    while (i < j)
    {
        if (nums[i] == val){
            while (nums[j] == val){
                j--;
                l++;
            }
            nums[i] = nums[j];
            l++;
        }
        i++;
    }
    return nums.size() - l;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
// int t;
// cin >> t;
vector<int> v = {1, 2, 3, 4, 5, 3, 3};
int n = removeElement(v, 3);
for (auto i : v)
{
    cout << i << " ";
}
cout << "this is " << n;
return 0;
}