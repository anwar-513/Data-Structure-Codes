/*
A warehouse sensor sends readings every second.
A dropped packet arrives as 0. A faulty sensor sends -1.

packets = [4, 0, 7, 0, 0, 12, 3, 0, 9]
1. Write moveZeroes using the swap version,
with the r != w guard. Return the number of swaps actually performed,
and print it. Show the result for the array above.
2. Write removeValue to strip every -1 marker from [5, -1, 8, -1, -1, 2, 6].
 Return the new length and print only the valid prefix, not the garbage tail.
On the cleaned data from part 2, find the second largest distinct reading using secondLargest.
3. Test it on [7, 7, 7] to show the false path.
4. Run moveZeroes on an array with no zeros and report the swap count.
 Explain in one line why the answer is what it is.
*/

#include<iostream>

using namespace std;

void printArr(int array[], int size)
{
    cout<<"[";
    for(int i = 0; i < size; i++)
    {
        cout<<array[i];
        if(i < size-1)
        {
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

void secondLargest(int array[], int size)
{
    if(size < 2) return;

    int largest = array[0];
    int secondLargest = 0;
    for(int i = 1; i < size; i++)
    {
        if(array[i] > largest)
        {
            secondLargest = largest;
            largest = array[i];
        }
    }

    printArr(array,size);
    cout<<"The second largest element of the array is : "<<secondLargest;
}

void moveZeroies(int array[], int size)
{
    int swap = 0;
    int w = 0;
    for(int r = 0; r < size; r++)
    {
        if(array[r] != 0)
        {
            if(r != w)
            {
                int temp = array[w];
                array[w] =array[r];
                array[r] = temp; 
                swap++;
            }
            w++;
        }
    }
    printArr(array, size);
    cout<<"Number of Swap = "<<swap<<endl<<endl;
}

void removeVal(int array[], int size)
{   
    int lenght = size;
    for(int i = 0; i < size; i++)
    {
        if(array[i] < 0)
        {
            for(int j = i; j < size; j++)
            {
                array[j] = array[j+1];
            }
            lenght--;
        }
        if(array[i] < 0) i--;
    }
    printArr(array, lenght);
//    secondLargest(array,lenght);
}

int main()
{
    const int size = 9;
    int packet[size] = {4, 0, 7, 0, 0, 12, 3, 0, -9};

    moveZeroies(packet, size);

    int size2 = 7;
    int packet2[size2] = {5, -1, 8, -1, -1, 2, 6};

    removeVal(packet2, size2);
    
    int size3 = 3;
    int packet3[size3] = {7, 7, 7};

    const int size4 = 5;
    int packet4[size4] = {3, 4, 5, 1, 4};

    moveZeroies(packet4, size4);

    return 0;
}