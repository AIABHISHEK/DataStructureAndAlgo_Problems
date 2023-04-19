#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// give the minimum number of the transformation required to make startWord to endword
void solve(string startWord, string endWord, vector<string>list){
    unordered_set<string> st(list.begin(), list.end());
    cout << "hello";
    st.erase(startWord);
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    int level = 0;
    while(!q.empty()){
        pair<string, int> word_level = q.front();
        q.pop();
        level = word_level.second;
        if (word_level.first == startWord){
            cout << level;
            return;
        }
            
        for (int i = 0; i < word_level.first.size(); i++){
            char original = word_level.first[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word_level.first[i] = ch;
                if (st.find(word_level.first) != st.end()){
                    st.erase(word_level.first);
                    q.push({word_level.first, word_level.second + 1});
                }
            }
            word_level.first[i] = original;
        }
    }
    cout << 0;
}

int main(){

ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

vector<string> st = {"hot", "dot", "dog", "lot", "log", "cog"};
string startWord = "hit";
string endWord = "hot";
solve(startWord, endWord, st);
return 0;
}