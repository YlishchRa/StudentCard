
#include "StudentCard.h"
#include <iostream>
using namespace std;

int main()
{
    StudentCard students[3] = {StudentCard("Yura", "Lishchynskyi", "NZF-22-1", "08-09-2022"),
                               StudentCard("Oleg", "Karbin", "EKO-20-3", "08-09-2020"),
                               StudentCard("Nastya", "Karterna", "NZF-22-1", "08-09-2022")};

    students[0].addItemToStudent("Bio", 4);
    students[0].addItemToStudent("Math", 4);
    students[0].addItemToStudent("Arts", 3);
    students[0].addItemToStudent("Gym", 5);
    students[0].addItemToStudent("Geo Physics", 4);

    students[1].addItemToStudent("Ecologia", 5);
    students[1].addItemToStudent("Math", 3);
    students[1].addItemToStudent("English", 4);
    students[1].addItemToStudent("Philisofy", 3);
    students[1].addItemToStudent("Topograph", 5);

    students[2].addItemToStudent("Bio", 3);
    students[2].addItemToStudent("Math", 5);
    students[2].addItemToStudent("Arts", 2);
    students[2].addItemToStudent("Gym", 4);
    students[2].addItemToStudent("Geo Physics", 5);

    for (int i = 0; i < 3; i++)
    {
        cout << students[i];
    }

    students[1].removeItem("English");

    for (int i = 0; i < 3; i++)
    {
        cout << students[i];
    }
    return 0;
}
