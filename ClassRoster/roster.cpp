#include "roster.h"
#include <iostream>

void Roster::parse(std::string dataRow) {
	// Variables to store parsed data to pass to add method
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	DegreeProgram degree;

	// Stores the passed data string to be parsed
	std::string dataText = dataRow;

	int comma1;
	int comma2;

	comma1 = dataText.find(',');

	studentID = dataText.substr(0, 2);
	std::cout << studentID;
}