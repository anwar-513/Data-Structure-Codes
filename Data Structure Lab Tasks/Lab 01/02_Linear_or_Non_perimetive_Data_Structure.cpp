#include <iostream>
using namespace std;
 
int main() {
    int marks[5] = {90, 89, 70, 61, 93};
    int sum = 0;
 
    cout << "----- Linear Data Structure (Array) Demo -----" << endl;
    cout << "Student Marks: " << endl;
 
    // Single sequential pass -> characteristic of a LINEAR data structure
    for (int i = 0; i < 5; i++) {
        cout << "Student " << (i + 1) << ": " << marks[i] << endl;
        sum += marks[i];
    }
 
    float average = (float) sum / 5;
    cout << "Average Marks: " << average << endl;
 
    return 0;
}
