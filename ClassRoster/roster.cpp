#include "roster.h"
#include <iostream>

void parse(std::string dataRow) {
	// Variables to store parsed data to pass to add method
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int daysToComplete[3];
	DegreeProgram degree;

	// Stores the passed data string to be parsed
	std::string dataText = dataRow;

	for (int i = 0; i < 7; i++) {
		int comma1;
		int comma2;

		comma1 = dataText.find(',');
	}
}