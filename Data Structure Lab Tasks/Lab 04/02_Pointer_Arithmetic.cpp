/*      PROBLEM

Write a program that dynamically allocates an array of n integers, 
then uses pointer arithmetic (not index notation) to reverse-print the
array from the last element to the first.
*/

#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter the number of integers: ";
	cin >> n;

	int* numbers = new int[n];

	cout << "Enter " << n << " integers: ";
	for (int* pointer = numbers; pointer < numbers + n; pointer++)
	{
		cin >> *pointer;
	}

	cout << "Array in reverse order: ";
	for (int* pointer = numbers + n - 1; pointer >= numbers; pointer--)
	{
		cout << *pointer << " ";
	}

	delete[] numbers;

	return 0;
}
