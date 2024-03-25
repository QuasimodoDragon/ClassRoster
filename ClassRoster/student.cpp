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
	this->daysToComplete[3] = { 0 };
	this->degree = DegreeProgram::SECURITY;
};

// Full attribute constructor
Student::Student(std::string ID, std::string nameFirst, std::string nameLast, std::string emailAddress, int studentAge, int daysToCompleteClass[], DegreeProgram degreeProgram) {
	studentID = ID;
	firstName = nameFirst;
	lastName = nameLast;
	email = emailAddress;
	age = studentAge;
	
	for (int i = 0; i < 3; i++) {
		daysToComplete[i] = daysToCompleteClass[i];
	}

	degree = degreeProgram;
}

std::string Student::getStudentID() const {
	return studentID;
}

void Student::setStudentID(std::string ID) {
	studentID = ID;
}

std::string Student::getFirstName() const {
	return firstName;
}

void Student::setFirstName(std::string name) {
	firstName = name;
}

std::string Student::getLastName() const {
	return lastName;
}

void Student::setLastName(std::string name) {
	lastName = name;
}

std::string Student::getEmail() const {
	return email;
}

void Student::setEmail(std::string emailAddress) {
	email = emailAddress;
}

int Student::getAge() const {
	return age;
}
void Student::setAge(int studentAge) {
	age = studentAge;
}

std::string Student::getDaysToComplete(int classPosition) {
	return std::to_string(daysToComplete[classPosition]);

	// Old code
	/*
	std::string text;
	
	for (int i = 0; i < 3; i++) {
		text += std::to_string(daysToComplete[i]);

		if (i < 2) {
			text.append(", ");
		}
	}

	return text;
	*/
}

void Student::setDaysToComplete(int classPosition, int days) {
	// Old code
	/*daysToComplete[0] = num1;
	daysToComplete[1] = num2;
	daysToComplete[2] = num3;*/
}

std::string Student::getDegree() const {
	// Old code
	//return degree;
}

void Student::setDegree(DegreeProgram degree) {
	// Old code
	//degree = degreeProgram;
}

void printHeader() {
	
};

void print() {
	
};