#include<iostream>
using namespace std;

bool flage1 = false;

void bubbleSort(char array[], int size)
{
    for(int i = 0; i < size-1; i++)
    {   
        bool flage = false;
        for(int j = 0; j < size-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(array[j],array[j+1]);
                flage = true;
                flage1 = true;
            }
        }
        if(!flage)
        {
            break;
        }
    }
        
}

void printArray(char array[], int size)
{
    cout<<endl;
    for(int i = 0; i < size; i++)
    {
        cout<<array[i]<<", ";
    }
}

void insertArray(char array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<"Enter the character of "<<i<<" index---> ";
        cin>>array[i];
        while(array[i] < 65 || array[i] > 122)
        {
            cout<<"Enter character nothing else is acceptable---> ";
            cin>>array[i];
        }
    }
}

int main()
{
    int size; 

    cout<<"Enter the value of size---> ";
    cin>>size;

    char array[size] = {0};

    insertArray(array, size);
    
    cout<<"_________Array Before________"<<endl;
    printArray(array, size);

    bubbleSort(array,size);

    
    cout<<"\n_________Array After___________"<<endl;
    printArray(array, size);

    if(flage1)
    {
    cout<<"\n\nNumber of Swap : "<<(size * (size - 1)) / 4<<endl;
    }
    else{
        cout<<"\n\nNo swap"<<endl;
    }
    cout<<"Number of Comparisons : "<<(size * (size -1) / 2)<<endl; 


    return 0;
}