


#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
*/

string decodeString(string s)
{
    cout << s << endl;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ']')
        {
            string r = "";
            while (st.top() != '[')
            {
                r.push_back(st.top());
                st.pop();
            }
            st.pop();            // remove [
            string count = "";
            while(!st.empty() && st.top() < 90){
                count.push_back(st.top());
                st.pop();
            }
            reverse(count.begin(), count.end());
            int n = 0;
            n = stoi(count);
            // st.pop();            // remove that number from stack
            cout << n << endl;
            // r string count times in stack;
            reverse(r.begin(), r.end());
            while (n >= 0)
            {
                for (int k = 0; k < r.size(); k++)
                {
                    st.push(r[k]);
                }
                n--;
            }
        }
        else{
            st.push(s[i]);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
string s;
cin >> s;
cout << decodeString(s);
return 0;
}