#include <iostream>

int main() {
	int rollNumber;
	float cgpa;
	char firstLetter;
	bool passed;

	std::cout << "Enter roll number: ";
	std::cin >> rollNumber;

	std::cout << "Enter CGPA: ";
	std::cin >> cgpa;

	std::cout << "Enter the first letter of your name: ";
	std::cin >> firstLetter;

	std::cout << "Did you pass? (1 for true, 0 for false): ";
	std::cin >> passed;

	std::cout << "\n----- Student Report -----\n";
	std::cout << "Roll number: " << rollNumber << '\n';
	std::cout << "CGPA: " << cgpa << '\n';
	std::cout << "First letter of name: " << firstLetter << '\n';
	std::cout << "Passed: " << std::boolalpha << passed << '\n';
	std::cout << "Total memory consumed: "
			  << sizeof(rollNumber) + sizeof(cgpa) + sizeof(firstLetter) + sizeof(passed)
			  << " bytes\n";

	return 0;
}
