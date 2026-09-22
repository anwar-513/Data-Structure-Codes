#include<iostream>
using namespace std;

int main()
{   
    int *ptr = new int[5];
    int sum = 0;
    int average =0;

    for(int i = 0; i < 5; i++){
        cout<<"Enter the "<< i <<" index value---> ";
        cin>>ptr[i];
        sum +=ptr[i]; 
    }

    for(int i = 0; i < 5; i++)
    {
        cout<<"You Entered the "<<i<<" index values   : "<<ptr[i]<<endl;
        cout<<"The "<<i<<" index is stored at    : "<<&ptr[i]<<endl;
    }

    average = sum/5;

    cout<<"\nSum :           "<<sum<<endl;
    cout<<"Average :       "<<average;


    return 0;
}