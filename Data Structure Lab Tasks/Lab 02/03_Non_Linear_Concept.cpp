#include <iostream>
#include <string>

using namespace std;

int main() {
	string manager = "Maya";
	string employees[4] = {"Alice", "Bob", "Carol", "David"};
	string interns[2] = {"Ivy", "Ian"};

	cout << manager << " (Manager)" << endl;

	for (int i = 0; i < 4; i++) {
		cout << "  |-- " << employees[i] << " (Employee)" << endl;

		// Alice is the first employee, so she has two interns.
		if (i == 0) {
			for (int j = 0; j < 2; j++) {
				cout << "      |-- " << interns[j]
					  << " (Intern)" << endl;
			}
		}
	}

	// This is a non-linear relationship because one person can have
	// many people below them in the hierarchy.
	// A single linear array only stores items one after another.
	// It does not clearly store who reports to whom, so extra indexes
	// or searches would be needed to find the relationships.
	return 0;
}
