#include "student.h"
#include <iostream>

int main() {

    /*const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kevin,Bailey,kbai350@wgu.edu,30,15,20,16,SOFTWARE"
    };*/

    // Test code
    int daysInClass[] = { 23,33,41 };
    Student bailey("A5", "Kevin", "Bailey", "kbai350@wgu.edu", 30, daysInClass, SOFTWARE);

    bailey.print();

    return 0;
}
