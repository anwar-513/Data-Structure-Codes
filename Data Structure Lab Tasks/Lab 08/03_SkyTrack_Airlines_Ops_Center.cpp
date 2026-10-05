/*
 * PROBLEM: Flight Delay Ranking System
 * -------------------------------------
 * Sort flights by delay time (descending) using Bubble Sort.
 * Keep flightNumbers[] matched to delayMinutes[] (parallel arrays).
 *
 * Input:
 *   flights = {"SK101","SK204","SK330","SK417","SK550","SK612"}
 *   delays  = {45, 10, 120, 5, 75, 0}
 *
 * Tasks:
 *   1. Bubble sort delays descending; swap flights[] in sync.
 *   2. Add early-exit optimization (stop if no swaps in a pass).
 *
 * No built-in sort allowed.
 */

 #include<iostream>
using namespace std;

void bubbleSort(string flight[], int delayTime[], int size)
{
    bool flage = false;
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(delayTime[j] < delayTime[j+1])
            {
                swap(flight[j],flight[j+1]);
                swap(delayTime[j],delayTime[j+1]);
                flage = true;
            }
        }
        
        if(!flage)
        {
           break;
        }
    }
}

void display(string arr1[], int arr2[], int size)
{
    cout<<"[";
    for(int i = 0; i < size; i++)
    {
        cout<<arr1[i]<<", ";
    }
    cout<<"]"<<endl<<"[";
    for(int i = 0; i < size; i++)
    {
        cout<<arr2[i]<<", ";
    }
    cout<<"]"<<endl;
}

int main()
{
    const int SIZE = 6;
    string* flightNumbers = new string[SIZE]{"SK101", "SK204", "SK330", "SK417", "SK550", "SK612"};
    int* delayMinutes =  new int[SIZE]{45, 10, 120, 5, 75, 0};

    cout<<"\n_______________FLIGHTS BEFORE_____________"<<endl;
    display(flightNumbers, delayMinutes, SIZE);
    
    
    cout<<"\n_______________FLIGHTS AFTER_____________"<<endl;
    bubbleSort(flightNumbers, delayMinutes, SIZE);
    display(flightNumbers, delayMinutes, SIZE);



    delete[] flightNumbers;
    delete[] delayMinutes;
    return 0;
}
