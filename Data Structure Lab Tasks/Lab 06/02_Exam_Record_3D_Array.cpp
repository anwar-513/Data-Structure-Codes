#include<iostream>
using namespace std;

int main()
{
    int marks[3][4][2];

    for(int p = 0; p < 3; p++)
    {
        for(int s = 0; s < 4; s++)
        {
            for(int sub = 0; sub < 2; sub++)
            {
                cout<<"Enter Paper "<<p+1<<" Student "<<s+1<<" Subject "<<sub+1<<" Marks---> ";
                cin>>marks[p][s][sub];
            }
        }
    }

    for(int s = 0; s < 4; s++)
    {
        int total = 0;

        for(int p = 0; p < 3; p++)
        {
            for(int sub = 0; sub < 2; sub++)
            {
                total = total + marks[p][s][sub];
            }
        }

        cout<<"Total marks of Student "<<s+1<<" is---> "<<total<<endl;
    }

    return 0;
}