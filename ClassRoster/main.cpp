#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>

int main() {

    // Prints personal information
    std::cout << "Scripting and Programming: Applications - C867" << '\n';
    std::cout << "Language: C++" << '\n';
    std::cout << "Student ID: 011012738" << '\n';
    std::cout << "Kevin Bailey" << '\n';
    std::cout << '\n';

    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kevin,Bailey,kbai350@wgu.edu,30,15,20,16,SOFTWARE"
    };

    Roster classRoster;

    // Adds all of the studentData strings and parses them to be created as Student objects and added to the classRoster Roster
    for (std::string student : studentData) {
        classRoster.parse(student);
    }

    classRoster.printAll();
    std::cout << '\n';

    classRoster.printInvalidEmails();
    std::cout << '\n';

    // Prints the average days in courses for each student in classRoster
    for (int i = 0; i < 5; i++) {
        std::string studentID = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }
    std::cout << '\n';

    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << '\n';

    classRoster.remove("A3");
    std::cout << '\n';

    classRoster.printAll();
    std::cout << '\n';

    // This should give a message saying A3 was not found because we deleted it earlier
    classRoster.remove("A3");
    std::cout << '\n';

    return 0;
}