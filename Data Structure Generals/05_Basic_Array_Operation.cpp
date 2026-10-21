/*
You receive an array of API response times (ms) from a
delivery-tracking service for one hour:

times = [120, 85, 300, 85, 410, 95, 85, 230, 60, 410]

Write functions to produce a report:

Return the slowest and fastest response time, 
and the index of the first occurrence of each.
Compute the average response time as a double.
Count how many requests were slower than the average.
Count the frequency of a given value x (test with x = 85 and x = 500).
Print the array in reverse order without modifying it and without a second array.

Then test with an all-negative array [-5, -2, -9] to prove your min/max initialization is correct.
*/

#include<iostream>

using namespace std;

void report(int array[], int size)
{
    int min = array[0];
    short minIndex = 0;
    int max = array[0];
    short maxIndex = 0;

    double sum = 0;
    double average = 0;


    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
            maxIndex = i;
        }
        if(array[i] < min)
        {
            min = array[i];
            minIndex = i;
        }
        sum += array[i];
    }

    average = sum / size;

    int countbelowAverage = 0;
    int countFrequency = 0;
    int i = 0;
    int frequency;

    cout<<"Enter the value for checking---> ";
    cin>>frequency;
    while(i < size)
    {
        if(array[i] > average)
        {
        countbelowAverage++;
        }
        if(array[i] == frequency)
        {
            countFrequency++;
        }
        i++;
    }

    cout<<"The Slowest response of Hour: "<<max<<endl;
    cout<<"The Slowest response is on '"<<maxIndex<<"' index"<<endl;
    
    cout<<"The Fastest response of Hour: "<<min<<endl;
    cout<<"The Fastest response is on '"<<minIndex<<"' index"<<endl;

    cout<<"The Average of the service hour is : "<<average<<endl;
    cout<<"The Request slower than Average is : "<<countbelowAverage<<endl;
    cout<<"The Given elements are '"<<countFrequency<<"' times available."<<endl;
}

void printReverse(int array[], int size)
{
    cout<<"[";
    for(int i = size-1; i >= 0; i--)
    {
        cout<<array[i];
        if(i > 0)
        {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}


int main()
{
    int SIZE = 10;
    int times[SIZE] = {120, 85, 300, 85, 410, 95, 85, 230, 60, 410};

    report(times, SIZE);
    printReverse(times, SIZE);

    return 0; 
}