#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

//given a string find all subsequence strings in which occurrence of all the characters are same
//for example: "abab" -> "abab", "ab", "ba", "aa", "bb", "a", "b",

int find_subsequence(string s, vector<int>& count, int i,int c){
    if(i == s.size()){
        if(c == 0)
            return 0;
        int c = -1;
        for(auto x: count){
            if(x!=0 && c == -1){
                c = x;
            }
            else if(x!= 0 && c!=x){
                return 0;
            }
        }
        return 1;
    }
    int ans = 0;
    count[s[i] - 'a']++;    
    ans += find_subsequence(s, count, i+1, c+1);
    count[s[i] - 'a']--;
    ans += find_subsequence(s, count, i+1, c);
    return ans;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
string st = "abca";
vector<int> count(26, 0);
cout<<find_subsequence(st, count, 0, 0);

return 0;
}