#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int
//
using namespace std;

//  problem link https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

/**
 * You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
*/

/**
 * SOLUTION APPROACH
 *
 * since each student must get atleast one book, and every book has to be allocated so the minimum number of pages anyone get is maximum of pages of given array of books since each book book must be allocated and ,
 * so value will range from max(array) to sum(array)
 */
bool isPossibleToAllocate(vector<int> &books, int max_pages, int students)
{
    // linear search to check if it is possible to allocate all books with given max number of pages to be allocated
    int currSum = 0;
    for (int i = 0; i < books.size(); i++)
    {
        if (students == 0)
            return 0; // no students is left to allocate books
        if (max_pages < currSum + books[i])
        {
            // if(currSum + books[i] > max_pages) so we make currSum = books[i] and decrease the number of student by 1 since we can not allocate more page to that student
            currSum = 0;
            students--;
        }
        currSum += books[i];
    }
    if (students == 0 && currSum != 0)
        return 0;
    // cout << maxNumPages << endl;
    return 1; //
}

int solve(vector<int> &books, int students)
{
    if (students >= books.size())
        return -1;
    // linear search to check if it is possible to allocate all books with given max number of pages to be allocated
    int max_pages = books[max_element(books.begin(), books.end()) - books.begin()];
    int total_pages = accumulate(books.begin(), books.end(), 0);

    // this has quadratic time complexity
    //  for (int i = max_pages; i <= total_pages; i++)
    //  {
    //      bool p = isPossibleToAllocate(books, i, students);
    //  if (p)
    //      {
    //          return i;
    //      }
    //      else
    //          continue;
    //  }

    // apply binary search
    int start = max_pages;
    int end = total_pages;
    int mid;
    int ans = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        bool p = isPossibleToAllocate(books, mid, students);
        if (p)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    vector<int> A = {12,
                     34,
                     67,
                     90};
    vector<int> B = {1,
                     4,
                     6,
                     9};
    int M = 2;
    cout << solve(B, M) << endl;
    cout << solve(B, 3);
    return 0;
}