#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;
// Given an expression, A, with operands and operators(OR, AND, XOR), in how many ways can you evaluate the expression to true, by grouping in different ways ?
//         Operands are only true and false. 

#include <iostream>
using namespace std;

int countWays(string expression, int start, int end, bool isTrue)
{
    // Base case: If the expression has only one character
    if (start == end)
    {
        if (isTrue && expression[start] == 'T')
        {
            return 1;
        }
        else if (!isTrue && expression[start] == 'F')
        {
            return 1;
        }
        return 0;
    }

    int ways = 0;

    // Evaluate each operator and recursively count the number of ways
    for (int k = start + 1; k <= end - 1; k += 2)
    {
        int leftTrue = countWays(expression, start, k - 1, true);
        int leftFalse = countWays(expression, start, k - 1, false);
        int rightTrue = countWays(expression, k + 1, end, true);
        int rightFalse = countWays(expression, k + 1, end, false);

        if (expression[k] == '&')
        {
            if (isTrue)
            {
                ways += leftTrue * rightTrue;
            }
            else
            {
                ways += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
            }
        }
        else if (expression[k] == '|')
        {
            if (isTrue)
            {
                ways += leftTrue * rightFalse + leftFalse * rightTrue + leftTrue * rightTrue;
            }
            else
            {
                ways += leftFalse * rightFalse;
            }
        }
        else if (expression[k] == '^')
        {
            if (isTrue)
            {
                ways += leftFalse * rightTrue + leftTrue * rightFalse;
            }
            else
            {
                ways += leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }
    }

    return ways;
}

int main()
{
    string expression;
    cout << "Enter the expression: ";
    cin >> expression;
    int n = expression.length();
    int ways = countWays(expression, 0, n - 1, true);
    cout << "Number of ways to evaluate the expression to true: " << ways << endl;
    return 0;
}