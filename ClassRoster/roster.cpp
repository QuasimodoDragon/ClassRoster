#include "roster.h"
#include <iostream>

void Roster::parse(std::string dataRow) {
	// Stores the passed data string to be parsed
	std::string dataText = dataRow;

	// After the comma is found the text before it is parsed as it's relative data
	int commaPosition = dataText.find(',');
	std::string studentID = dataText.substr(0, commaPosition - 0);
	// Everything in dataText up to the comma is deleted, so we only have to look for a comma the next time
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string firstName = dataText.substr(0, commaPosition - 0);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string lastName = dataText.substr(0, commaPosition - 0);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string email = dataText.substr(0, commaPosition - 0);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string ageString = dataText.substr(0, commaPosition - 0);
	int age = std::stoi(ageString);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string days1String = dataText.substr(0, commaPosition - 0);
	int daysInCourse1 = std::stoi(days1String);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string days2String = dataText.substr(0, commaPosition - 0);
	int daysInCourse2 = std::stoi(days2String);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string days3String = dataText.substr(0, commaPosition - 0);
	int daysInCourse3 = std::stoi(days3String);
	dataText.erase(0, commaPosition + 1);

	commaPosition = dataText.find(',');
	std::string degreeString = dataText.substr(0, commaPosition - 0);
	DegreeProgram degree;
	if (degreeString == "SECURITY") {
		degree = SECURITY;
	}
	else if (degreeString == "NETWORK") {
		degree = NETWORK;
	}
	else {
		degree = SOFTWARE;
	}

	// Uses all parsed data to add a student object to the roster
	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

// Called during the parse method
void Roster::add(
	std::string studentID, 
	std::string firstName, 
	std::string lastName, 
	std::string emailAddress, 
	int age, 
	int daysInCourse1, 
	int daysInCourse2, 
	int daysInCourse3, 
	DegreeProgram degreeProgram
) {
	// Creates a new student on the first available index of the classRosterArray
	classRosterArray[++lastStudentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::remove(std::string studentID) {
	bool found = false;

	// Loops through the classRosterArray as many times as there are visible students in the classRosterArray
	for (int i = 0; i <= lastStudentIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;

			// If the student is not the last element in the classRosterArray then it will be swapped with the last element
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}

			// This decrements the number of visible student objects in the classRosterArray to hide the removed student object
			lastStudentIndex--;
			break;
		}
	}

	if (found) {
		std::cout << "The student was removed." << '\n';
	}
	else if (!found) {
		std::cout << "The student with the ID: " << studentID << " Was not found." << '\n';
	}
}

// Prints all student data in a table
void Roster::printAll() {
	Student::printHeader();

	for (int i = 0; i <= lastStudentIndex; i++) {
		classRosterArray[i]->print();
	}
}

// Prints the average days in course for the passed student
void Roster::printAverageDaysInCourse(std::string studentID) {
	bool found = false;
	
	for (int i = 0; i <= lastStudentIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;

			// Converts the returned string from getDaysToComplete to an int so we can perform some math
			int class1 = std::stoi(classRosterArray[i]->getDaysToComplete(0));
			int class2 = std::stoi(classRosterArray[i]->getDaysToComplete(1));
			int class3 = std::stoi(classRosterArray[i]->getDaysToComplete(2));

			int average = (class1 + class2 + class3) / 3;
			std::cout << "Student ID: " << studentID << ", Average days in course: " << average << '\n';
		}
	}

	if (!found) {
		std::cout << "The student with the ID: " << studentID << " Was not found." << '\n';
	}
}

// Validates student emails and prints the emails that didn't pass validation
void Roster::printInvalidEmails() {
	for (int i = 0; i < numStudents; i++) {
		std::string studentEmail = classRosterArray[i]->getEmail();

		// If the email does not contain an '@' or a '.' or if there is a space then the email is invalid
		if ((studentEmail.find('@') == std::string::npos) || (studentEmail.find('.') == std::string::npos) || (studentEmail.find(' ') != std::string::npos)) {
			std::cout << studentEmail << " - is invalid." << '\n';
		}
	}
}

// Filters the students based on the passed program and prints a table of the students in that program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	// Converts the passed DegreeProgram enum to a string
	std::string degreeString = degreeProgramString[degreeProgram];
	Student::printHeader();
	
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getDegree() == degreeString) {
			classRosterArray[i]->print();
		}
	}
}

// Since the roster creates student objects dynamically the desctructor needs to loop through the classRosterArray and delete them manually
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		// The desctructor deletes the student object and adds a nullptr in it's place
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}