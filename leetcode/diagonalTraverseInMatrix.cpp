#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>> matrix)
{
    if (matrix.size() == 0)
    {
        vector<int> v(0, 0);
        return v;
    }

    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<int> v(rows * columns);

    int currentRow = 0;
    int currentColumn = 0;
    bool goUp = true;

    for (int i = 0; i <rows + columns ; i++)
    {
        if (goUp) // moving up
        {
            v[i] = matrix[currentRow--][currentColumn++];

            // exceed the boundary
            if (!(currentRow >= 0 && currentColumn <= columns - 1))
            {
                // return to the previous valid position
                currentRow++;
                currentColumn--;

                // Going to the element right to it(same row, next column) is always preferable
                // while changing the direction from moving up to moving down
                // unless the next column is invalid
                if (currentColumn < columns - 1)
                    currentColumn++;
                else
                    currentRow++;

                // will move down for next iteration
                goUp = false;
            }
        }
        else // moving down
        {
            v[i] = matrix[currentRow++][currentColumn--];

            // exceed the boundary
            if (!(currentRow <= rows - 1 && currentColumn >= 0))
            {
                // return to the previous valid position
                currentRow--;
                currentColumn++;

                // Going to the element below it(same column, next row) is always preferable
                // while changing the direction from moving down to moving up
                // unless the next row is invalid
                if (currentRow < rows - 1)
                    currentRow++;
                else
                    currentColumn++;
                // will move up for next iteration
                goUp = true;
            }
        }
    }
    return v;
}
    int main(){
        ios_base::sync_with_stdio(false); // fastio
        cin.tie(NULL);                    // fastio
        int t;
        cin >> t;
        return 0;
    }