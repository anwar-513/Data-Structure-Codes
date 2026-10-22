#include<iostream>
using namespace std;

bool handle(int size, int index)
{
    if(index < 0 || index > size) return false;
    if(size >= 10) return false;
    return true;
}

void insertAt(int array[], int& size, int index, int id)
{
    if(handle(size, index))
    {
        for(int i = size; i > index; i--)
        {
            array[i] = array[i-1];
        }
        array[index] = id;
        size++;
    }
    else{
        cout<<"Invalid Operation";
    }
}

void deleteAt(int array[], int& size, int index)
{
    if(index < 0 || index >= size)
    {
        cout<<"Invalid Operation";
        return;
    }

    for(int i = index; i < size - 1; i++)
    {
        array[i] = array[i+1];
    }
    size--;
}

int linearSearch(int array[], int size, int id)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == id)
            return i;
    }
    return -1;
}

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
    cout<<"]";
}

void printSalesGrid()
{
    const int BRANCHES = 3;
    const int DAYS = 4;
    int sales[BRANCHES][DAYS] =
    {
        {10, 20, 30, 40},
        {5, 15, 25, 35},
        {8, 8, 8, 8}
    };
    int branchTotals[BRANCHES] = {0};
    int dayTotals[DAYS] = {0};
    int highestBranch = 0;

    for(int branch = 0; branch < BRANCHES; branch++)
    {
        for(int day = 0; day < DAYS; day++)
        {
            branchTotals[branch] += sales[branch][day];
            dayTotals[day] += sales[branch][day];
        }

        if(branchTotals[branch] > branchTotals[highestBranch])
        {
            highestBranch = branch;
        }
    }

    cout<<"\nSales total per branch:"<<endl;
    for(int branch = 0; branch < BRANCHES; branch++)
    {
        cout<<"Branch "<<branch + 1<<": "<<branchTotals[branch]<<endl;
    }

    cout<<"Sales total per day:"<<endl;
    for(int day = 0; day < DAYS; day++)
    {
        cout<<"Day "<<day + 1<<": "<<dayTotals[day]<<endl;
    }

    cout<<"Branch with highest total: Branch "<<highestBranch + 1
        <<" ("<<branchTotals[highestBranch]<<")"<<endl;
}

void printSubarrays()
{
    int array[] = {3, 1, 2};
    int size = sizeof(array) / sizeof(array[0]);
    int count = 0;

    cout<<"\nSubarrays of [3, 1, 2]:"<<endl;
    for(int start = 0; start < size; start++)
    {
        for(int end = start; end < size; end++)
        {
            cout<<"[";
            for(int i = start; i <= end; i++)
            {
                cout<<array[i];
                if(i < end)
                {
                    cout<<", ";
                }
            }
            cout<<"]"<<endl;
            count++;
        }
    }

    int expectedCount = size * (size + 1) / 2;
    cout<<"Subarray count: "<<count
        <<" (expected "<<expectedCount<<")"<<endl;
}

int main()
{
    const int SIZE = 10;

    int packages[SIZE] = {101, 102, 103, 104, 105};
    int size = 5;

    int index;
    int id;

    cout<<"|_____________________________________________|"<<endl;
    cout<<"|---------------Shelf Manager-----------------|"<<endl;
    cout<<"|_____________________________________________|"<<endl;

    while(true)
    {
        int choice;
        cout<<"\n(1) Insertion      (2) Deletion      (3) Search"<<endl;
        cout<<"(4) Continue to sales grid and subarrays      (5) Exit"<<endl;
        cout<<"Enter the Option---> ";
        if(!(cin>>choice))
        {
            return 1;
        }

        switch (choice)
        {
        case 1:
            cout<<"Enter the index of insertion---> ";
            cin>>index;
            cout<<"Enter the value for insertion---> ";
            cin>>id;

            insertAt(packages,size,index,id);
            printArr(packages, size);
            cout<<endl;
        break;
        case 2:
            cout<<"\n\nEnter the index number for deletions---> ";
            cin>>index;

            deleteAt(packages, size, index);
            printArr(packages, size);
            cout<<endl;

        break;
        case 3:
        {
            cout<<"Enter the ID to Search---> ";
            cin>>id;

            int target = linearSearch(packages, size, id);
            if(target != -1)
            {
                cout<<"The ID is on '"<<target<<"' index.";
            }
            else
            {
                cout<<"NOT FOUND!!!"<<endl;
            }
            printArr(packages, size);
            cout<<endl;
            break;
        }
        case 4:
            printSalesGrid();
            printSubarrays();
            return 0;
        case 5:
            return 0;
        default:
            cout<<"INVALID CHOICE"<<endl;
            break;
        }
    }

    return 0;
}
