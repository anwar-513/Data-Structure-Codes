#include<iostream>
using namespace std;

int main()
{
    int row;
    int colom;

    cout<<"Enter the row size---> ";
    cin>>row;
    cout<<"Enter the colom size---> ";
    cin>>colom;


    int **array = new int*[row];
    
    for(int i = 0; i < colom; i++)
    {
        array[i] = new int[colom];
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colom; j++)
        {
            cout<<"Enter the value of["<<i<<"] & ["<<j<<"] index---> ";
            cin>>*(*(array+i)+j);
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colom; j++)
        {
            cout<<*(*(array+i)+j)<<" ";
        }
        cout<<endl;
    }

        for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colom; j++)
        {
            cout<<(*(array+i)+j)<<" ";
        }
        cout<<endl;
    }

            for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < colom; j++)
        {
            cout<<"["<<i<<"]["<<j<<"]  ";
        }
        cout<<endl;
    }

    delete[] array[0];
    delete[] array[1];
    delete[] array;

    return 0;
}