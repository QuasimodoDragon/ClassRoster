#include "student.h"
#include <iostream>

int main() {
    // test code
    Student taylor;

    taylor.setStudentID(42069);
    std::cout << taylor.getStudentID() << '\n';

    taylor.setFirstName("Taylor");
    std::cout << taylor.getFirstName() << '\n';

    taylor.setLastName("Bailey");
    std::cout << taylor.getLastName() << '\n';

    taylor.setEmail("josh@yahoo.boy");
    std::cout << taylor.getEmail() << '\n';

    taylor.setAge(4000);
    std::cout << taylor.getAge() << '\n';

    taylor.setDaysToComplete(12, 13, 43);
    std::cout << taylor.getDaysToComplete() << '\n';

    taylor.setDegree("Piss");
    std::cout << taylor.getDegree() << '\n';

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
