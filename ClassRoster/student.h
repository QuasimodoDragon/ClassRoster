#pragma once

class Student {
	public:
		int getStudentID() const;
		void setStudentID(int ID);
	private:
		int studentID;
		std::string firstName;
		std::string lastName;
		std::string email;
		int age;
		int daysToComplete[3];
		std::string degree;
};