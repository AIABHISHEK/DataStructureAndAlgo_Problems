#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
int shortestDistanceInMaze(vector<vector<int>> matrix, vector<int> source, vector<int> des){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    q.push({source[0], source[1]});
    dist[source[0]][source[1]] = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(x == des[0] && y == des[1]){
            return dist[x][y];
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == 1 && dist[nx][ny] > dist[x][y] + 1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<vector<int>> m = {{1, 1, 0, 1},
                        {0, 1, 1, 1},
                        {1, 0, 0, 1},
                        {1, 0, 1, 1}};
vector<int> source = {0, 0};
vector<int> des = {3, 3};
cout << shortestDistanceInMaze(m, source, des)<<endl;
cout << shortestDistanceInMaze(m, source, {2, 3});

return 0;
}