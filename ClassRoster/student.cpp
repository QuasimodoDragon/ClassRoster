#include "student.h"
#include <iostream>
#include <string>

// Default constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = 0;
	}
	this->degree = DegreeProgram::SECURITY;
};

// Full attribute constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysToComplete[], DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degree = degree;
}

std::string Student::getStudentID() const {
	return studentID;
}

void Student::setStudentID(std::string studentID) {
	this->studentID = studentID;
}

std::string Student::getFirstName() const {
	return firstName;
}

void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

std::string Student::getLastName() const {
	return lastName;
}

void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
}

std::string Student::getEmail() const {
	return email;
}

void Student::setEmail(std::string email) {
	this->email = email;
}

int Student::getAge() const {
	return age;
}
void Student::setAge(int age) {
	this->age = age;
}

std::string Student::getDaysToComplete(int classPosition) {
	return std::to_string(daysToComplete[classPosition]);
}

void Student::setDaysToComplete(int classPosition, int days) {
	daysToComplete[classPosition] = days;
}

std::string Student::getDegree() const {
	return degreeProgramString[degree];
}

void Student::setDegree(DegreeProgram degree) {
	this->degree = degree;
}

void Student::printHeader() {
	std::cout << "Format: ID|First Name|Last Name|Email|Age|Days in Course|Degree Program" << '\n';
};

void Student::print() {
	std::cout << this->studentID << '\t';
	std::cout << this->firstName << '\t';
	std::cout << this->lastName << '\t';
	std::cout << this->email << '\t';
	std::cout << this->age << '\t';
	std::cout << this->daysToComplete[0] << ',';
	std::cout << this->daysToComplete[1] << ',';
	std::cout << this->daysToComplete[2] << '\t';
	std::cout << degreeProgramString[this->degree] << '\n';
};