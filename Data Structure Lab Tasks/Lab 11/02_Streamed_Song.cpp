/*
Two regions, North America (america) and europerope (europe), maintain separate
lists of top-streamed songs sorted in descending order. The task is
to merge these two arrays into one global leaderboard
while preserving the descending order.

Implement the **Merge step of Merge Sort** using pointers
to compare the current elements of both arrays and insert
the larger element into a new array. Continue until all
elements are merged. Do not use any built-in sorting functions.

*/

#include<iostream>
using namespace std;

void merge(int array1[], int size1, int array2[], int size2, int merged[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < size1  && j < size2)
    {
        if(array1[i] > array2[j])
        {
             merged[k] = array1[i];
            i++;
            k++;
        }
        else {
             merged[k] = array2[j];
            j++;
            k++;
        }
    }

    while(i < size1)
    {
         merged[k] = array1[i];
        i++;
        k++;
    }

    while(j < size2)
    {
         merged[k] = array2[j];
        j++;
        k++;
    }
}

void print(int array[], int size)
{
    cout<<"[";
    for(int i = 0; i < size; i++)
    {
        cout<<array[i];
        if(i < size -1)
        {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}



int main()
{
    int america[] = {
    985000, 940000, 875000, 820000, 765000,
    710000, 655000, 600000, 545000, 490000,
    435000, 380000, 325000, 270000, 215000
    };
    int size1 = sizeof(america) / sizeof(america[0]); 

    int europe[] = {
    970000, 925000, 890000, 845000, 800000,
    755000, 700000, 665000, 620000, 575000,
    530000, 475000, 420000, 365000, 200000
    };
    int size2 = sizeof(europe) / sizeof(europe[0]);

     int* merged = new int[size1 + size2];


    merge(america, size1, europe, size2, merged);

    print(merged,(size1 + size2));

  delete[] merged;

    return 0;
}