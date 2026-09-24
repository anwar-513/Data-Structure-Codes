#include<iostream>
using namespace std;

int main()
{
    int size;
    
    cout<<"Enter the size of the Array---> ";
    cin>>size;

    int* array = new int[size];

    for(int i = 0; i < size; i++)
    {
        cout<<"Enter the "<<i<<" index element---> ";
        cin>>*(array+i);
    }

    for(int i = size-1; i >= 0; i--)
    {
        cout<<*(array+i)<<", ";
    }

    delete array;

    return 0;
}