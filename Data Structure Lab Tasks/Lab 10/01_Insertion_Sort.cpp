#include<iostream>

using namespace std;

int main()
{
    const int SIZE = 8;
    int shifts = 0;
    int array[SIZE] = {8,12,1,5,17,19,6,5};

    cout<<"___________Array Before____________"<<endl<<"[";
    for(int i = 0; i < SIZE; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"]"<<endl;

    for(int i = 1; i < SIZE; i++)
    {
        int key = array[i];
        int j = i-1;
        while(j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
            shifts++;
        }
        array[j+1] = key;
    }

    
    cout<<"___________Array After___________"<<endl<<"[";
    for(int i = 0; i < SIZE; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"]"<<endl;

    cout<<"Number of Shifts: "<<shifts<<endl;

    return 0;

}