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
	int commaPosition;

	commaPosition = dataText.find(',');
	studentID = dataText.substr(0, commaPosition - 0);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	firstName = dataText.substr(0, commaPosition - 0);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	lastName = dataText.substr(0, commaPosition - 0);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	email = dataText.substr(0, commaPosition - 0);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string ageString = dataText.substr(0, commaPosition - 0);
	age = std::stoi(ageString);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string days1String = dataText.substr(0, commaPosition - 0);
	daysInCourse1 = std::stoi(days1String);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string days2String = dataText.substr(0, commaPosition - 0);
	daysInCourse2 = std::stoi(days2String);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string days3String = dataText.substr(0, commaPosition - 0);
	daysInCourse3 = std::stoi(days3String);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string degreeString = dataText.substr(0, commaPosition - 0);
	if (degreeString == "SECURITY") {
		degree = SECURITY;
	}
	else if (degreeString == "NETWORK") {
		degree = NETWORK;
	}
	else {
		degree = SOFTWARE;
	}

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	classRosterArray[lastStudentIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}


// This function breaks program when called. The index swapping is the culprit
void Roster::remove(std::string studentID) {
	bool found = false;

	for (int i = 0; i < Roster::lastStudentIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;

			// If the object found is not the last item in the classRosterArray it will swap places with the next student object in the array
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}

			// This decrements the number of visible student objects in the classRosterArray to hide the removed student object
			Roster::lastStudentIndex--;
		}
	}

	if (found) {
		std::cout << "The student was removed." << '\n';
	}
	else if (!found) {
		std::cout << "The student with the ID: " << studentID << " Was not found." << '\n';
	}
}