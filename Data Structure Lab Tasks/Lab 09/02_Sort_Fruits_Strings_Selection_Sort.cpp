#include <iostream>
#include <string>

using namespace std;

const int MAX_STRINGS = 100;

bool isSmaller(string a, string b)
{
    int i = 0;

    while (i < a.length() && i < b.length())
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
        i++;
    }

    return a.length() < b.length();
}

void printStrings(string strings[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << strings[i] << " ";
    }
    cout << endl;
}

void selectionSort(string strings[], int n, int order,
                   int& comparisons, int& swaps)
{
    for (int i = 0; i < n - 1; i++)
    {
        int selectedIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (order == 1 && isSmaller(strings[j], strings[selectedIndex]))
            {
                selectedIndex = j;
            }
            else if (order == 2 && isSmaller(strings[selectedIndex], strings[j]))
            {
                selectedIndex = j;
            }
        }

        if (selectedIndex != i)
        {
            string temporary = strings[i];
            strings[i] = strings[selectedIndex];
            strings[selectedIndex] = temporary;
            swaps++;
        }

        cout << "Pass " << i + 1 << ": ";
        printStrings(strings, n);
    }
}

int main()
{
    string strings[MAX_STRINGS];
    int n;

    cout << "Enter number of strings (1-" << MAX_STRINGS << "): ";
    cin >> n;

    if (n < 1 || n > MAX_STRINGS)
    {
        cout << "Please enter a number from 1 to " << MAX_STRINGS << "." << endl;
        return 1;
    }

    cout << "Enter strings: ";
    for (int i = 0; i < n; i++)
    {
        cin >> strings[i];
    }

    int order;
    cout << "Choose order (1 = ascending, 2 = descending): ";
    cin >> order;

    if (order != 1 && order != 2)
    {
        cout << "Please choose 1 or 2." << endl;
        return 1;
    }

    int comparisons = 0;
    int swaps = 0;
    selectionSort(strings, n, order, comparisons, swaps);

    cout << "Sorted: ";
    printStrings(strings, n);
    cout << "Comparisons: " << comparisons << " | Swaps: " << swaps << endl;

    return 0;
}