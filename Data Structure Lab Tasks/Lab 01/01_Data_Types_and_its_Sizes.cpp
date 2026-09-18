#include <iostream>
using namespace std;
 
int main() {
    int age = 21;
    float height = 5.9f;
    double weight = 68.256;
    char grade = 'A';
    bool isRegistered = true;
 
    cout << "----- Primitive Data Structures Demo -----" << endl;
    cout << "Age (int)         : " << age << "\t         Size: " << sizeof(age) << " bytes" << endl;
    cout << "Height (float)    : " << height << "\t         Size: " << sizeof(height) << " bytes" << endl;
    cout << "Weight (double)   : " << weight << "\t Size: " << sizeof(weight) << " bytes" << endl;
    cout << "Grade (char)      : " << grade << "\t\t Size: " << sizeof(grade) << " bytes" << endl;
    cout << "Registered (bool) : " << isRegistered << "\t\t Size: " << sizeof(isRegistered) << " bytes" << endl;
 
    return 0;
}
