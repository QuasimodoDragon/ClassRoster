#include "student.h"
#include <iostream>

void parse(std::string dataRow) {
	// Variables to store parsed data to pass to add method
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int daysToComplete[3];
	DegreeProgram degree;

	// Stores the passed data string to be parsed
	std::string dataText = dataRow;

	for (int i = 0; i < 7; i++) {
		int comma1;
		int comma2;

		comma1 = dataText.find(',');
		std::cout << comma1;
	}
}

int main() {

    /*const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kevin,Bailey,kbai350@wgu.edu,30,15,20,16,SOFTWARE"
    };*/

    // Test code
    Student bailey("A5", "Kevin", "Bailey", "kbai350@wgu.edu", 30, 32, 44, 56, SOFTWARE);

    bailey.print();

	parse("A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY");

    return 0;
}
