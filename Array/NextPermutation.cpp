#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void perm(vector<int>& nums){
    int index = -1;
        for(int i = nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                index = i-1;
                break;
            }
        }
        if(index != -1)
        for(int i = nums.size() - 1; i>=0; i--){
            if(nums[i] > nums[index]){
               int temp = nums[i];
               nums[i] = nums[index];
               nums[index] = temp;
            break;
            }
        }
        int i = index + 1;
        int j = nums.size() - 1;
        while(i<=j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

vector<int> a = {3,2,1};
perm(a);
for (auto &i : a)
{
    cout<<i<<" ";
}

return 0;
}