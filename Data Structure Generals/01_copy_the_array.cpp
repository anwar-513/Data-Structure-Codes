/*  PROBLEM
Copy an array into a new vector,
 change the copy, and confirm the 
 original did not change. Append three 
 items using a loop.
 
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& values)
{
    cout << "[";
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << values[i];
    }
    cout << "]" << endl;
}

int main()
{
    const int SIZE = 5;
    int array[SIZE] = {5, 6, 3, 2, 1};
    vector<int> copy(array, array + SIZE);

    cout << "Original array: ";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << array[i] << (i + 1 < SIZE ? ' ' : '\n');
    }

    cout << "Copied vector: ";
    printVector(copy);

    copy[0] = 10;
    copy.pop_back();

    
    cout << "After changing the copy:" << endl;
    cout << "Original array: ";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << array[i] << (i + 1 < SIZE ? ' ' : '\n');
    }
    cout << "Copied vector: ";
    printVector(copy);


    return 0;
}