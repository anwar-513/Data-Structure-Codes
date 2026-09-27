#include<iostream>
using namespace std;

int main()
{
    int marks[3][4][2];

    for(int paper = 0; paper < 3; paper++)
    {
        for(int student = 0; student < 4; student++)
        {
            for(int subject = 0; subject < 2; subject++)
            {
                cout<<"Enter Paper "<<paper+1<<" Student "<<student+1<<" Subject "<<subject+1<<" Marks---> ";
                cin>>marks[paper][student][subject];
            }
        }
    }

    for(int student = 0; student < 4; student++)
    {
        int total = 0;

        for(int paper = 0; paper < 3; paper++)
        {
            for(int subject = 0; subject < 2; subject++)
            {
                total = total + marks[paper][student][subject];
            }
        }

        cout<<"Total marks of Student "<<student+1<<" is---> "<<total<<endl;
    }

    return 0;
}