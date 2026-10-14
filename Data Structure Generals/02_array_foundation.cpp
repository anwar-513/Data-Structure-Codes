/*
A teacher stores marks of 10 students in a vector: {56, 78, 90, 45, 67, 78, 88, 34, 90, 72}. 
Write one program that does, in this order:
1. Print all marks (traversal).
2. Print the sum and average (1.2).
3. Print the highest and lowest marks (1.3).
4. Ask for a mark and tell the first position where it appears, or "not found" (1.4).
5. Count how many students scored 90 (1.4).
6. A late student scored 81: insert it at index 3 (1.5). Then delete the student at index 0 who left (1.6).
7. Append two more marks with push_back and print the final size (1.8).
8. Count how many marks are even and odd (1.2).
9. Print every subarray of the first 3 marks (1.7).
10. Store the marks of 3 students in 3 subjects as a 2D array and print each student's total (1.9).
*/

#include<iostream>
#include<vector>

using namespace std;


int main()
{
    vector<int> marks = {56, 78, 90, 45, 67, 78, 88, 34, 90, 72};
    int sum = 0;
    int count = 0;
    int target;
    double average = 0;
    int min = marks[0];
    int max = marks[0];

    for(size_t i = 0; i < marks.size(); i++)
    {
        cout<<i+1<<" Student"<<" marks : "<<marks[i]<<endl;
        sum = sum + marks[i];
        if(marks[i] < min)
        {
            min = marks[i];
        }
        if(marks[i] > max)
        {
            max = marks[i];
        }
        if(marks[i] == 90)
        {
            count++;
        }
    }

    average = sum / 10;

    cout<<"\n Sum : "<<sum<<endl;
    cout<<"Average : "<<average<<endl;
    cout<<"Minimum : "<<min<<endl;
    cout<<"Maximum : "<<max<<endl;

    cout<<"Enter the marks for the search---> ";
    cin>>target;

    for(size_t i = 0; i < marks.size(); i++)
    {
        if(marks[i] == target)
        {
            cout<<"Target Found at "<<i<<" index"<<endl;
            break;
        }
        else {
            cout<<"Not Found!!"<<endl;
        }
    }

    cout<<count<<" Students scores 90"<<endl;
    






    return 0;
}