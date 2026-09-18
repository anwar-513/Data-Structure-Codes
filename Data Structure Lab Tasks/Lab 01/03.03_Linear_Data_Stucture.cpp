/*
Write a C++ program that declares an integer array of 10 elements,
 takes values from the user, and then: (a) prints all elements, (b)
  finds and prints the maximum and minimum values, (c) calculates and prints 
  the sum of all elements — using single-pass sequential traversal.
*/

  #include <iostream>

  using namespace std;

  int main() {
    int values[10];
    int maximum;
    int minimum;
    int sum = 0;

    cout << "Enter 10 integer values:\n";

    for (int index = 0; index < 10; ++index) {
      cin >> values[index];
      cout << values[index] << ' ';

      if (index == 0) {
        maximum = values[index];
        minimum = values[index];
      } else {
        if (values[index] > maximum) {
          maximum = values[index];
        }
        if (values[index] < minimum) {
          minimum = values[index];
        }
      }

      sum += values[index];
    }

    cout << "\n\nMaximum: " << maximum << '\n';
    cout << "Minimum: " << minimum << '\n';
    cout << "Sum: " << sum << '\n';

    return 0;
  }