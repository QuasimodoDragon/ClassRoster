#pragma once

#include "student.h"
#include <iostream>

class Roster {
	public:
		void parse(std::string dataRow);
		void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void remove(std::string studentID);

		// Print methods
		void printAll();
		void printAverageDaysInCourse(std::string studentID);
		// Prints student emails with invalid format
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);

	private:
		// There are 5 students in the student table so this array doesn't need to be dynamic
		Student* classRosterArray[5];
};