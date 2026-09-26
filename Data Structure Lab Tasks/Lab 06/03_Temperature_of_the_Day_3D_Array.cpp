#include<iostream>
using namespace std;

int main()
{
    int days = 0;
    int hours = 0;
    int sensors = 0;

    cout<<"Enter number of days---> ";
    cin>>days;
    cout<<"Enter number of hours per day---> ";
    cin>>hours;
    cout<<"Enter number of sensors per hour---> ";
    cin>>sensors;

    // 1. Allocate the outer layer: one pointer per day
    int ***temp = new int**[days];

    for(int d = 0; d < days; d++)
    {
        // 2. Allocate the middle layer: one pointer per hour, for this day
        temp[d] = new int*[hours];

        for(int h = 0; h < hours; h++)
        {
            // 3. Allocate the inner layer: one int per sensor, for this hour
            temp[d][h] = new int[sensors];
        }
    }

    // 4. Fill the array with input
    for(int d = 0; d < days; d++)
    {
        for(int h = 0; h < hours; h++)
        {
            for(int s = 0; s < sensors; s++)
            {
                cout<<"Enter Day "<<d+1<<" Hour "<<h+1<<" Sensor "<<s+1<<" Reading---> ";
                cin>>temp[d][h][s];
            }
        }
    }

    // 5. Calculate and print the average for each day
    for(int d = 0; d < days; d++)
    {
        int total = 0;

        for(int h = 0; h < hours; h++)
        {
            for(int s = 0; s < sensors; s++)
            {
                total = total + temp[d][h][s];
            }
        }

        double average = (double)total / (hours * sensors);

        cout<<"Average temperature for Day "<<d+1<<" is---> "<<average<<endl;
    }

    // 6. Deallocate memory in reverse order
    for(int d = 0; d < days; d++)
    {
        for(int h = 0; h < hours; h++)
        {
            delete[] temp[d][h];
        }
        delete[] temp[d];
    }
    delete[] temp;

    return 0;
}