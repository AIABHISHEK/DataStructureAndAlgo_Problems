#include<bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

/**
 * Compute the maximum area of a rectangle in a histogram.
 *
 * @param histogram The input vector representing the histogram.
 *
 * @return The maximum area of a rectangle in the histogram.
 *
 * @throws None
 */
int maxRect(vector<int>& histogram){
    int n = histogram.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    stack<int> s;
    int i = 0;
    
    // Step 1: Compute left boundary for each bar
    left[0] = 0;
    s.push(0);
    i++;
    while(i < n){
        int last = i;
        while(!s.empty() && histogram[s.top()] >= histogram[i]){
            last = s.top();
            s.pop();
        }
        left[i] = s.empty() ? 0 : last;
        s.push(i);
        i++;
    }
    
    // Step 2: Compute right boundary for each bar
    while(!s.empty()) s.pop();
    i = n-1;
    right[n-1] = n-1;
    s.push(n-1);
    i--;
    while(i>=0){
        int last = i;
        while(!s.empty() && histogram[s.top()] >= histogram[i]){
            last = s.top();
            s.pop();
        }
        right[i] = s.empty() ? n-1 : last;
        s.push(i);
        i--;
    }

    // Step 3: Find the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++){
        maxArea = max(maxArea, histogram[i] * (right[i] - left[i] + 1));
    }
    return maxArea;
}

//optimized approach
int maxRect2(vector<int> &histogram)
{
    int n = histogram.size();
    stack<int> s;
    int maxArea = 0;

    // Step 1: Compute max area using heights of bars in histogram
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && (i == n || histogram[s.top()] >= histogram[i]))
        {
            int height = histogram[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    return maxArea;
}

int main(){
ios_base::sync_with_stdio(false); // fastio
cin.tie(NULL); // fastio
vector<int> v = {2, 1, 5, 6, 2, 3, 1};
cout<<maxRect2(v);

return 0;
}