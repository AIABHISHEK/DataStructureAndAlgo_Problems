#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    int mod = 1e5;
    queue<pair<int, int>> q;       // curr , steps
    vector<int> dis(1e5 - 1, 1e9); // to keep track that we visited that number and do not end visited again
    q.push({start, 0});
    while (!q.empty())
    {
        long long curr = q.front().first;
        int step = q.front().second;
        q.pop();
        if (curr == end)
            return step;
        for (int i = 0; i < arr.size(); i++)
        {
            int num = (curr * (long long)arr[i]) % mod;
            if (dis[num] > step + 1)
            {
                dis[num] = step + 1;
                q.push({num, step + 1});
            }
        }
    }
    return -1;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

//
vector<int> nums = {2, 3, 5};
int start = 1;
int end = 10;
cout << minimumMultiplications(nums, start, end);
return 0;
}