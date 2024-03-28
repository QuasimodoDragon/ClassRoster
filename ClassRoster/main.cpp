#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>

int main() {

    /*const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kevin,Bailey,kbai350@wgu.edu,30,15,20,16,SOFTWARE"
    };*/

    // Test code
    Roster roster;

    roster.parse("A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY");
    roster.parse("A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK");
    roster.parse("A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE");
    roster.remove("A2");
    roster.remove("A3");

    return 0;
}