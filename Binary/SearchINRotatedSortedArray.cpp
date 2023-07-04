#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// Given the rotated sorted array after the possible rotation and an integer target, return the index of target if it is in array, or -1 if it is not in array.

/**
 * Searches for a target value in a vector of integers using the binary search algorithm with small changes.
 *
 * @param v the vector of integers to search in
 * @param target the target value to search for
 *
 * @return the index of the target value in the vector if found, -1 otherwise
 *
 * @throws None
 * 
 * 
 * @bug drawback of given algorithm is that it will not work for duplicate values in the vector and this problem occurs if v[start] == v[end] == v[mid] so in this case if target != v[start] then our target is present somewhere between start+1 and mid-1 so we shrink our search space
 */

int search(vector<int> v, int target)
{
    int start = 0;          // Initialize the start index to 0
    int end = v.size() - 1; // Initialize the end index to the last index of the vector
    int mid;                // Declare a variable to store the middle index
    while (start <= end)    // Loop until the start index is less than or equal to the end index
    {
        mid = start + (end - start) / 2; // Calculate the middle index
        if (v[mid] == target)            // If the middle element is equal to the target value
            return mid;                  // Return the middle index
        else if (v[mid] > target)        // If the middle element is greater than the target value
        {
            if (v[mid] < v[end]) // If the middle element is less than the last element of the vector i.e means the array from mid to end is sorted(ascending order) and since target is greater than mid element so it is greater than the last element so target is present somewhere between start and mid so we update end index to mid - 1
            {
                end = mid - 1; // Update the end index to mid - 1
            }
            else
            {
                // since array is not sorted from mid to end (then it is sorted from start to mid) so we check if target is less than the first element of the array or not if it is less than first element then it is present somewhere between mid+1 and end so we update start index to mid + 1 //
                if (v[start] > target) // If the first element is greater than the target value
                    start = mid + 1;   // Update the start index to mid + 1
                // if target is greater than or equal to the first element then it is present somewhere between start and mid-1 because the array is sorted(ascending order) from start to mid-1 and and target is less than mid element so we update end index to mid - 1
                else
                    end = mid - 1; // Update the end index to mid - 1
            }
        }
        else // If the middle element is less than the target value
        {
            if (v[mid] < v[end]) // If the middle element is less than the last element
            {
                // since array is sorted from mid to end so we check if target is less than or equal to the end element of the array or not if it is less than or equal to than end element then it is present somewhere between mid+1 and end so we update start index to mid + 1 //
                if (v[end] >= target) // If the end element is greater than or equal to the target value
                    start = mid + 1;  // Update the start index to mid + 1
                // is target is greater that end element then target is present between start to mid -1 so we update end index to mid - 1
                else
                    end = mid - 1; // Update the end index to mid - 1
            }
            // since array is not sorted (mid to end is not sorted so they are sorted from start to mid) and element at mid is less than target so if target exits it would be somewhere between mid+1 and end so we update start index to mid + 1
            else
            {
                start = mid + 1; // Update the start index to mid + 1
            }
        }
    }
    return -1; // Return -1 if the target value is not found
}

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> v = {3,1,2,3,3,3,3}; will not work for this case

    cout << search(v, 1) << endl;   // return 4
    cout << search(v, 2) << endl;   // return 6
    cout << search(v, 3) << endl;   // return 0
    cout << search(v, 100) << endl; // return -1
    return 0;
}