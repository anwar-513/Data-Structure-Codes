#include<iostream>

using namespace std;


int main()
{
    const int SIZE = 8;

    int count = 0;
    int array[SIZE] = {5,1,8,12,27,3,7,9};


    cout<<"\n____________ARRAY BEFORE SORTING_____________"<<endl<<"[";
    for(int i = 0; i < SIZE; i++)
    {
        cout<<array[i]<<", ";
    }
    cout<<"]"<<endl;

    for(int i = 0; i < SIZE-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j < SIZE; j++)
        {
            if(array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            swap(array[i],array[minIndex]);
            count++;
        }
    }



    cout<<"\n____________ARRAY AFTER SORTING_____________"<<endl<<"[";
    for(int i = 0; i < SIZE; i++)
    {
        cout<<array[i]<<", ";
    }
    cout<<"]"<<endl;
    cout<<"\nNumber of swaps : "<<count<<endl;

    return 0;
}