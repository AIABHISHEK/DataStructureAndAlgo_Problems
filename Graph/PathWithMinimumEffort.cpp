#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// problem link https://leetcode.com/problems/path-with-minimum-effort/

/**
 * Finds the minimum effort path in a grid of heights.
 *
 * @param heights a 2D vector representing the grid of heights
 *
 * @return the minimum effort required to travel from the top-left corner to the bottom-right corner
 *  Minimum effort is max absolute diff of of to nodes in path  
 * @throws None
 */
int minimumEffortPath(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // {diff, {i, j}}
    dis[0][0] = 0;
    pq.push({0, {0, 0}});
    vector<int> a = {-1, 0, 1, 0};
    vector<int> b = {0, 1, 0, -1};
    while (!pq.empty()){
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        int distance = pq.top().first;
        if (i == m - 1 && j == n - 1)
            return dis[m - 1][n - 1];
        pq.pop();
        for (int k = 0; k < 4; k++)
        {
            int in = i + a[k];
            int jn = j + b[k];
            if (in >= 0 && in < m && jn >= 0 && jn < n)
            {
                int diff = max(abs(heights[i][j] - heights[in][jn]), distance);
                if (diff < dis[in][jn])
                {
                    dis[in][jn] = diff;
                    pq.push({dis[in][jn], {in, jn}});
                }
            }
        }
    }
    return dis[m - 1][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    
    return 0;
}