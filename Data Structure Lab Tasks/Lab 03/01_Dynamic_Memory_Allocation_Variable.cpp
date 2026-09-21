#include<iostream>
using namespace std;


int main()
{
    int *ptr = new int; 

    cout<<"Enter an integer---> ";
    cin>>*ptr;

    cout<<"You entered     :"<<*ptr<<endl;
    cout<<"Stored at heap  :"<<ptr<<endl;

    delete ptr;      // Free the allocated memory
    ptr = nullptr;  // avoid dangling

    cout<<"Memory deallocated successfully"<<endl;
}