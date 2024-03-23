#include "student.h"
#include <iostream>

int Student::getStudentID() const {
	return studentID;
}

void Student::setStudentID(int ID) {
	studentID = ID;
}