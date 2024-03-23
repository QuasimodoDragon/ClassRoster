#include "student.h"
#include <iostream>
#include <string>

int Student::getStudentID() const {
	return studentID;
}

void Student::setStudentID(int ID) {
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

std::string Student::getDaysToComplete() const {
	std::string text;
	
	for (int i = 0; i < 3; i++) {
		text += std::to_string(daysToComplete[i]);

		if (i < 2) {
			text.append(", ");
		}
	}

	return text;
}

void Student::setDaysToComplete(int num1, int num2, int num3) {
	daysToComplete[0] = num1;
	daysToComplete[1] = num2;
	daysToComplete[2] = num3;
}

std::string Student::getDegree() const {
	return degree;
}

void Student::setDegree(std::string degreeProgram) {
	degree = degreeProgram;
}