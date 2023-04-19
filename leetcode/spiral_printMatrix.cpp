#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

vector<int> spiralPrint(vector<vector<int>> v){
    int top = 0;
    int bottom = v.size();
    int left = 0;
    int right = v[0].size();
    vector<int> nums;
    while (left < right && top < bottom){

        
        if(left<right){
            cout << 1 << endl;
            for (int i = left; i < right; i++){
                nums.push_back(v[top][i]);
            }
            top++;
        }

        if(top<bottom){
            cout << 2 << endl;
            for (int i = top; i < bottom; i++){
                nums.push_back(v[i][right - 1]);
            }
            right--;
        }

        if (left < right && top < bottom)
        {
            cout << 3 << endl;
            for (int i = right - 1; i >= left; i--){
                nums.push_back(v[bottom - 1][i]);
            }
            bottom--;
        }
        if(top < bottom){
            cout << 4 << endl;
            for (int i =  bottom - 1; i >= top; i--){
                nums.push_back(v[i][left]);
            }
            left++;
        }
    }
    return nums;
}

// 3
// 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12 
int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<int> a = spiralPrint(v);
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}