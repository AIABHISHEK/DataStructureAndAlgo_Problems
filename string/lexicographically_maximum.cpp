#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// given a string delete characters duplicates occurence until all the charcaters in string are distinct return the lexicographically maximum string that we can obtain

string removeDuplicateLetters(string s)
{
    reverse(s.begin(), s.end());
    vector<int> lastIndex(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        lastIndex[s[i] - 'a'] = i; // track the lastIndex of character presence
    }

    vector<bool> seen(26, false); // keep track seen
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        int curr = s[i] - 'a';
        if (seen[curr])
            continue; // if seen continue as we need to pick one char only
        while (st.size() > 0 && st.top() > s[i] && i < lastIndex[st.top() - 'a'])
        {
            seen[st.top() - 'a'] = false; // pop out and mark unseen
            st.pop();
        }
        st.push(s[i]);     // add into stack
        seen[curr] = true; // mark seen
    }

    string ans = "";
    while (st.size() > 0)
    {
        ans += st.top();
        st.pop();
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
string s = "ababc";
cout << removeDuplicateLetters(s) << endl;
return 0;
}