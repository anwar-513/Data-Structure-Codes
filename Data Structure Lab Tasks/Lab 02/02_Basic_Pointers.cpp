#include <iostream>
using namespace std;
 
int main() {
    int num = 50;
    int *ptr;
	ptr= &num;   // ptr stores the address of num
    int num2=100;
 
    cout << "----- Pointer Basics Demo -----" << endl;
    cout << "Value of num          : " << num << endl;
    cout << "Address of num (&num) : " << &num << endl;
    cout << "Value stored in ptr   : " << ptr << endl;
    cout << "Value pointed by ptr  : " << *ptr << endl;
 
    // Modify num indirectly through the pointer

    ptr = &num2;
    cout << "Value of num          : " << num2 << endl;
    cout << "Address of num (&num) : " << &num2 << endl;
    cout << "Value stored in ptr   : " << ptr << endl;
    cout << "Value pointed by ptr  : " << *ptr << endl;      
    return 0;
}
