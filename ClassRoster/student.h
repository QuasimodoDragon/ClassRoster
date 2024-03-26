#pragma once

#include "degree.h"
#include <iostream>

class Student {
	public:
		// Default constructor
		Student();
		// Constructor with parameters for each class variable
		Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysToComplete[], DegreeProgram degree);

		// Getters and setters for each class attribute
		std::string getStudentID() const;
		void setStudentID(std::string studentID);
		std::string getFirstName() const;
		void setFirstName(std::string firstName);
		std::string getLastName() const;
		void setLastName(std::string lastName);
		std::string getEmail() const;
		void setEmail(std::string email);
		int getAge() const;
		void setAge(int age);
		std::string getDaysToComplete(int classPosition);
		void setDaysToComplete(int classPosition, int days);
		std::string getDegree() const;
		void setDegree(DegreeProgram degree);

		// Print methods
		// Prints data table header
		void printHeader();
		// Prints student data for this instance
		void print();

	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string email;
		int age;
		int daysToComplete[3];
		DegreeProgram degree;
};