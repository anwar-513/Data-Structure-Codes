/*
You receive an array of API response times (ms) from a
delivery-tracking service for one hour :

times = [120, 85, 300, 85, 410, 95, 85, 230, 60, 410]

Report the slowest and fastest response time and the index of the
first occurrence of each. Compute the average, count requests slower
than average, count a given value, and print the array in reverse.
Then test with an all-negative array to verify min/max initialization.
*/

#include <iostream>

using namespace std;

struct Stats
{
    int max;
    int maxIndex;
    int min;
    int minIndex;
    double average;
};

Stats analyze(const int array[], int size)
{
    Stats stats = {array[0], 0, array[0], 0, 0.0};
    double sum = 0.0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > stats.max)
        {
            stats.max = array[i];
            stats.maxIndex = i;
        }
        if (array[i] < stats.min)
        {
            stats.min = array[i];
            stats.minIndex = i;
        }
        sum += array[i];
    }

    stats.average = sum / size;
    return stats;
}

int countAbove(const int array[], int size, double average)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > average)
        {
            count++;
        }
    }
    return count;
}

int countFreq(const int array[], int size, int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            count++;
        }
    }
    return count;
}

void printReverse(const int array[], int size)
{
    cout<<"[";
    for (int i = size - 1; i >= 0; i--)
    {
        cout<<array[i];
        if (i > 0)
        {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

void report(const int array[], int size)
{
    if (size <= 0)
    {
        cout<<"Cannot report on an empty array."<<endl;
        return;
    }

    Stats stats = analyze(array, size);
    cout<<"The slowest response time : "<<stats.max<<endl;
    cout<<"First occurrence index : "<<stats.maxIndex<<endl;
    cout<<"The fastest response time : "<<stats.min<<endl;
    cout<<"First occurrence index : "<<stats.minIndex<<endl;
    cout<<"Average response time : "<<stats.average<<endl;
    cout<<"Requests slower than average : "
        <<countAbove(array, size, stats.average)<<endl;
}

int main()
{
    const int SIZE = 10;
    int times[SIZE] = {120, 85, 300, 85, 410, 95, 85, 230, 60, 410};
    int negativeTimes[] = {-5, -2, -9};

    cout<<"____________Response-time report____________"<<endl;
    report(times, SIZE);
    cout<<"Frequency of 85 : "<<countFreq(times, SIZE, 85)<<endl;
    cout<<"Frequency of 500 : "<<countFreq(times, SIZE, 500)<<endl;
    cout<<"Array in reverse : ";
    printReverse(times, SIZE);

    cout<<endl<<"__________All-negative array report________"<<endl;
    report(negativeTimes, 3);

    return 0;
}
