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

    int target;
    cout<<"Enter the element you want to search----> ";
    cin>>target;


    for(int i = 0; i < size; i++)
    {
        if(*(array+i)==target){
            cout<<"The target is on "<<i<<" index."<<endl;
        }
    }

    return 0;

    delete array;
}