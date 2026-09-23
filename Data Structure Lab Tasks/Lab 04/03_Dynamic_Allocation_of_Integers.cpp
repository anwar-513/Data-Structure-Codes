/*
Write a program that dynamically allocates an integer array based on
 a user-specified size, fills it with user input, finds the maximum
  and minimum elements, and deallocates the array afterward.
*/

#include <iostream>
using namespace std;

int main()
{
	int size;

	cout << "Enter the size of the array: ";
	cin >> size;

	int* numbers = new int[size];

	cout << "Enter " << size << " integers:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> numbers[i];
	}

	int maximum = numbers[0];
	int minimum = numbers[0];

	for (int i = 1; i < size; i++)
	{
		if (numbers[i] > maximum)
		{
			maximum = numbers[i];
		}

		if (numbers[i] < minimum)
		{
			minimum = numbers[i];
		}
	}

	cout << "Maximum element: " << maximum << endl;
	cout << "Minimum element: " << minimum << endl;

	delete[] numbers;

	return 0;
}