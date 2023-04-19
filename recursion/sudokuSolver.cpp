#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

bool isValid(int k, vector<vector<int>> &sudoku, int i , int j){
    for (int l = 0; l < 9; l++){
        if (sudoku[i][k] == k)
            return false;
        if(sudoku[k][j] == k)
            return false;
    }
    for (int x = (i / 3) * 3; x < (i / 3) * 3 + 3; x++){
        for (int y = (j / 3) * 3; y < (j / 3) * 3 + 3; y++){
            if (sudoku[k][j] == k)
                return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &sudoku){

for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
            if(!sudoku[i][j]){
                for (int k = 1; k <= 9; k++){
                    if (isValid(k, sudoku, i, j)){
                        sudoku[i][j] = k;
                        if (!solve(sudoku)){
                            sudoku[i][j] = 0;
                        }
                        else{
                            return true;
                        }
                    }
                }
            return false;
        }
    }
}
return true;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
int t;
cin >> t; 


return 0;
}