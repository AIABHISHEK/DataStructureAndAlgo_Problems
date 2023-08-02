/**
 * @file nestedClass.cpp
 * @author ABHISHEK https://github.com/AIABHISHEK
 * @brief
 * @version 0.1
 * @date 2023-08-02
 *
 * @copyright Copyright (c) 2023
 *
 *
 * A nested class is a class which is declared in another enclosing class. 
 * A nested class is a member and as such has the same access rights as any other member. 
 * The members of an enclosing class have no special access to members of a nested class; the usual access rules shall be obeyed.
 */

#include <iostream>

using namespace std;

/* start of Enclosing class declaration */
class Enclosing
{
private:
    int x;

    /* start of Nested class declaration */
    class Nested
    {
        int y;
        void NestedFun(Enclosing *e)
        {
            cout << e->x; // works fine: nested class can access
                          // private members of Enclosing class
            // declarations in a nested class shall not use non-static data members or non - static member functions from the enclosing class
        }
    }; // declaration Nested class ends here
};     // declaration Enclosing class ends here

int main()
{
    
}
