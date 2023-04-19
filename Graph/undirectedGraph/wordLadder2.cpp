#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

void solve(string startWord, string endWord, vector<string> wordList){
    set<string> st(wordList.begin(), wordList.end());
    // in queue we will store the sequence in queue
    queue<vector<string>> q;
    q.push({startWord});
    int l;
    vector<vector<string>> ans;
    vector<string> stringList = q.front(); 
    vector<string> remove = {startWord};
    int level = 0;
    while(!q.empty()){
        stringList = q.front();
        l = stringList.size();
        
        cout << level;
        if(stringList.size() > level){
            level++;
            for (auto it : remove)
            {
                st.erase(it);
            }
            remove.clear();
        }
        
        q.pop();
        string word = stringList.back();
        if(word == endWord){
            if(ans.size() == 0){
                ans.push_back(stringList);
            }
            else if(ans[0].size() == stringList.size()){
                ans.push_back(stringList);
            }
        }
        
        for (int i = 0; i<word.size(); i++){
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++){
                
                word[i] = ch;
                if(st.find(word) != st.end()){
                    stringList.push_back(word);
                    remove.push_back(word);
                    q.push(stringList);
                    stringList.pop_back();
                }
                word[i] = original;
            }

        }
        
    }
    // cout << ans.size();
    for(auto it: ans){
        for (auto i: it){
            cout <<i<<" ";
        }
        cout << endl;
    }
}


int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio

vector<string> st = {"hot", "dot", "dog", "lot", "log", "cog"};
string startWord = "hit";
string endWord = "cog";
solve(startWord, endWord, st);

return 0;
}