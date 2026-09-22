#include <iostream>
using namespace std;
 
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;   // array name decays to a pointer to its first element
 
    cout << "----- Pointer Arithmetic Demo -----" << endl;
    cout << "Traversing array using pointer arithmetic:" << endl;
 
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << " = " << *(ptr + i)
             << "  (address: " << (ptr + i) << ")" << endl;
    }
 
    cout << "\nTraversing using pointer increment (ptr++):" << endl;
    int *p = arr;
    for (int i = 0; i < 5; i++) {
        cout << *p << " ";
        p++;   // move pointer to the next integer location
    }
    cout << endl;
 
      
    return 0;
}
