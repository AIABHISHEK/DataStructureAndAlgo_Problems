#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> links;
    bool f = true;
    TrieNode()
    {
        links = vector<TrieNode *>(26, NULL);
    }
};

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio


return 0;
}