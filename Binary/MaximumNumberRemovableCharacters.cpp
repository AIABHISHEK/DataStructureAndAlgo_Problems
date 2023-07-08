#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// problem link https://leetcode.com/problems/maximum-number-of-removable-characters/description/

/**
 * Checks if a given string is a subsequence of another string.
 *
 * @param s the original string
 * @param p the subsequence string
 * @param k the number of characters to remove from `s`
 * @param removable a vector of indices representing characters to remove from `s`
 * @param removed a vector of flags indicating if a character has been removed from `s`
 *
 * @return true if `p` is a subsequence of `s` after removing `k` characters, false otherwise
 *
 * @throws None
 */
bool isSubsequence(string s, string p, int k, vector<int> &removable, vector<int> &removed)
{
    for (int i = 0; i < k; i++)
    {
        removed[removable[i]] = 1;
    }
    int i = 0;
    int j = 0;
    while (i < s.size() && j < p.size())
    {
        if (removed[i])
        {

            i++;
            continue;
        }
        else if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    for (i = 0; i < k; i++)
    {
        removed[removable[i]] = 0;
    }
    return j == p.size();
}
/**
 * Find the maximum number of removals that can be done on string s
 * while keeping it a subsequence of string p.
 *
 * @param s The input string s.
 * @param p The input string p.
 * @param removable The indices of characters in s that can be removed.
 *
 * @return The maximum number of removals that can be done.
 *
 * @throws None.
 */
int maximumRemovals(string s, string p, vector<int> &removable)
{
    int start = 1;
    int end = removable.size();
    int ans = 0;
    int mid;
    int slen = s.size();
    vector<int> removed(slen, 0);
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isSubsequence(s, p, mid, removable, removed))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

string s = "abcacb", p = "ab";
vector<int> removable = {3, 1, 0};
// output 2
cout<<maximumRemovals(s, p, removable);
return 0;
}