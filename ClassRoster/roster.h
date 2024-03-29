#pragma once

#include "student.h"
#include <iostream>

class Roster {
	public:
		void parse(std::string dataRow);
		void add(
			std::string studentID, 
			std::string firstName, 
			std::string lastName, 
			std::string emailAddress, 
			int age, 
			int daysInCourse1, 
			int daysInCourse2, 
			int daysInCourse3, 
			DegreeProgram degreeProgram
		);
		void remove(std::string studentID);

		// Print methods
		void printAll();
		void printAverageDaysInCourse(std::string studentID);
		// Prints student emails with invalid format
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);

	private:
		const static int numStudents = 5;
		// This keeps track of how many students are in the classRosterArray. It is dynamic and will increment or decrement if a student is added or removed
		int lastStudentIndex = -1;
		
	public:
		// This is made public so we can access it in the main function and more easily access each students information
		Student* classRosterArray[numStudents];
};