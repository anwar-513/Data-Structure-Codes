#include <iostream>
using namespace std;
 
int main() {
    string parent = "XYZ";
    string children[3] = {"ABC", "DEF", "GHI"};
 
    cout << "----- Non-Linear Relationship (Tree Concept) Demo -----" << endl;
    cout << parent << " is connected to multiple children (non-linear, hierarchical relationship):" << endl;
 
    // Notice: one parent relates to MULTIPLE elements at once -> non-linear relationship
    for (int i = 0; i < 3; i++) {
        cout << parent << " -> " << children[i] << endl;
    }
    return 0;
}
