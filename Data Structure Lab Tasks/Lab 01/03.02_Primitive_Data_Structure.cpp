/*  Problem
Write a C++ program that swaps the values of two integer
 variables without using a third variable, and explain 
 (as a comment in the code) why this is possible only because
  int is a primitive data type stored directly in memory.
*/

#include <iostream>

using namespace std;

int main() {
    int firstValue;
    int secondValue;

    cout << "Enter the first integer: ";
    cin >> firstValue;

    cout << "Enter the second integer: ";
    cin >> secondValue;

    cout << "Before swapping: first = " << firstValue
      << ", second = " << secondValue << '\n';

    // int is a primitive data type whose value is stored directly in memory,
    // so bitwise operations can swap the values without a third variable.
    firstValue = firstValue ^ secondValue;
    secondValue = firstValue ^ secondValue;
    firstValue = firstValue ^ secondValue;

    cout << "After swapping: first = " << firstValue
      << ", second = " << secondValue << '\n';

    return 0;
}