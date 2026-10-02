#include<iostream>
using namespace std;

void bubbleSort(int array[], int size)
{
    for(int i = 0; i < size-1; i++)
    {   
        bool flage = false;
        for(int j = 0; j < size-i-1; j++)
        {
            if(array[j] < array[j+1])
            {
                swap(array[j],array[j+1]);
                flage = true;
            }
        }
        if(!flage)
        {
            cout<<"\nThe Array is sorted..."<<endl;
            break;
        }
    }
        
}

void printArray(int array[], int size)
{
    cout<<endl;
    for(int i = 0; i < size; i++)
    {
        cout<<array[i]<<", ";
    }
}

void insertArray(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<"Enter the value of "<<i<<" index---> ";
        cin>>array[i];
    }
}

int main()
{
    int size; 

    cout<<"Enter the value of size---> ";
    cin>>size;

    int array[size] = {0};

    insertArray(array, size);
    
    cout<<"_________Array Before________"<<endl;
    printArray(array, size);

    bubbleSort(array,size);

    
    cout<<"_________Array After___________"<<endl;
    printArray(array, size);


    cout<<"\nNumber of Swap : "<<(size * (size - 1)) / 4<<endl;
    cout<<"Number of Comparisons : "<<(size * (size -1) / 2)<<endl; 


    return 0;
}