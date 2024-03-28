#include "roster.h"
#include <iostream>

void Roster::parse(std::string dataRow) {
	// Stores the passed data string to be parsed
	std::string dataText = dataRow;

	int commaPosition = dataText.find(',');
	std::string studentID = dataText.substr(0, commaPosition - 0);
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

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

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
	classRosterArray[++lastStudentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	std::cout << "Last student Index after adding: " << lastStudentIndex << '\n';
}

// REWORK
void Roster::remove(std::string studentID) {
	bool found = false;

	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;

			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}

			// This decrements the number of visible student objects in the classRosterArray to hide the removed student object
			lastStudentIndex--;
			std::cout << "Last student Index after removing: " << lastStudentIndex << '\n';
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

void Roster::printAll() {
	Student::printHeader();

	for (int i = 0; i <= lastStudentIndex; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(std::string studentID) {
	bool found = false;
	
	for (int i = 0; i <= lastStudentIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;

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

void Roster::printInvalidEmails() {
	for (int i = 0; i < numStudents; i++) {
		std::string studentEmail = classRosterArray[i]->getEmail();

		if ((studentEmail.find('@') == std::string::npos) || (studentEmail.find('.') == std::string::npos) || (studentEmail.find(' ') != std::string::npos)) {
			std::cout << studentEmail << " - is invalid." << '\n';
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	std::string degreeString = degreeProgramString[degreeProgram];
	Student::printHeader();
	
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getDegree() == degreeString) {
			classRosterArray[i]->print();
		}
	}
}