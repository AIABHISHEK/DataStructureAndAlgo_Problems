#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

bool isPalindrome(string s, int start, int end){
    if(start >= end)
        return true;
    return ((s[start] == s[end]) && (isPalindrome(s, start + 1, end - 1)));
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
string s;
cin >> s;
cout<<isPalindrome(s, 0, s.length() - 1);


return 0;
}