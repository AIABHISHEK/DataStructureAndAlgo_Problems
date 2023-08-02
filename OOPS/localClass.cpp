

/**
 * @file localClass.cpp
 * @author ABHISHEK (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-08-02
 *
 * @copyright Copyright (c) 2023
 *
 *
 * A class declared inside a function becomes local to that function and is called Local Class in C++.

A local class name can only be used locally i.e., inside the function and not outside it.
The methods of a local class must be defined inside it only.
A local class can have static functions but, not static data members.
 */

// C++ program without any compilation error
// to demonstrate a Local Class
#include <iostream>
using namespace std;

// Creating the class
void fun()
{
    // local to fun
    class Test
    {
        // members of Test class
    };
}

// Driver Code
int main() { return 0; }
