#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

// link https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
/**
 * Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by board[i] where board is an array of n integers. He hired painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.
 *
 */

/**
 * Determines if it is possible to paint the board with the given constraints.
 *
 * @param board a vector of integers representing the lengths of each board section
 * @param painter the number of painters available
 * @param max_len the maximum length that a painter can paint
 *
 * @return true if it is possible to paint the board, false otherwise
 */
bool isPossibleToPaint(vector<int> &board, int painter, int max_len)
{
    int currLen = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (painter == 0)
            return false;
        if (currLen + board[i] > max_len)
        {
            currLen = 0;
            painter--;
        }
        currLen += board[i];
    }
    if (painter == 0 && currLen != 0)
        return false;
    return true;
}
/**
 * Finds the minimum time required to finish a painting job.
 *
 * @param board A reference to a vector of integers representing the length of each board.
 * @param painter The number of painters available.
 *
 * @return The minimum time required to finish the job.
 *
 * @throws None.
 */
int solve(vector<int> &board, int painter)
{
    // if board.size() == number of painter then time to finish the job is maximum element of board beacuse time per unit len is unit time
    // so this will be minimum time to finish the job if we have number of painter equal to number of board
    // But if we have lesser number of painter then time will increase and it can go upto sum of all element of board array in case there is only one painter
    // so our answer will be between these cases, so we check linearly in between thses once we found return
    int max_len = board[max_element(board.begin(), board.end()) - board.begin()];
    int total_len = accumulate(board.begin(), board.end(), 0); // total length
    //this approach will havce quadratic time complexity
    // for (int i = max_len; i <= total_len; i++)
    // {
    //     if (isPossibleToPaint(board, painter, i))
    //         return i;
    //     else
    //         continue;
    // }
    //use binary search
    int start = max_len, end = total_len;
    int mid;
    int ans = -1;
    while(start<=end){
        mid = start + (end - start) / 2;
        if(isPossibleToPaint(board, painter, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio

    int k = 3;
    vector<int> board = {5,
                         10,
                         30,
                         20,
                         15};
    cout << solve(board, k);
    return 0;
}