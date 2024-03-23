#pragma once

#include <iostream>

class Student {
	public:
		Student(int ID, std::string nameFirst, std::string nameLast, std::string emailAddress, int studentAge, int daysToComplete[], std::string degreeProgram);
		int getStudentID() const;
		void setStudentID(int ID);
		std::string getFirstName() const;
		void setFirstName(std::string name);
		std::string getLastName() const;
		void setLastName(std::string name);
		std::string getEmail() const;
		void setEmail(std::string emailAddress);
		int getAge() const;
		void setAge(int studentAge);
		std::string getDaysToComplete() const;
		void setDaysToComplete(int num1, int num2, int num3);
		std::string getDegree() const;
		void setDegree(std::string degreeProgram);

	private:
		int studentID;
		std::string firstName;
		std::string lastName;
		std::string email;
		int age;
		int daysToComplete[3];
		std::string degree;
};