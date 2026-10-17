#include<iostream>
using namespace std;

const short SIZE = 9;

void printArray(int array[])
{
    cout<<"[";
    for(int i = 0; i < SIZE; i++)
    {
        cout<<array[i];
        if(i < SIZE-1)
        {
            cout<<", ";
        }
    }
    cout<<"]\n\n"<<endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int temp[SIZE];
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid) 
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergesort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}




int main()
{
    int array[SIZE] = {27, 13, 1, 4, 2, 40, 7, 38, 3};

    int left = 0;
    int right = SIZE - 1;

    mergesort(array, left, right);

    printArray(array);


    return 0;
}
