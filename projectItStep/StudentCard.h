#pragma once
#include <iostream>
using namespace std;

class StudentCard {
    string name;
    string surname;
    string groupName;
    string dataIntroduction;

    // built in class StudentInfo
    class StudentInfo {
        string* listOfLection;
        int* rating;
        int numberOfItems;
        int maxListOfItem;

    public:
        StudentInfo();
        StudentInfo(int size);
        friend ostream& operator<<(ostream& output, const StudentInfo& stdInf)
        {
            for (int i = 0; i < stdInf.numberOfItems; i++) {
                output << "Name of item: " << stdInf.listOfLection[i] << "\t"
                       << "Rating of item: " << stdInf.rating[i] << "\n\t";
            }
            output << "\n";
            return output;
        }
        void addItem(const char* item, int ratingItem);

        void removeItem(const char* item);

        ~StudentInfo();
    };
    StudentInfo studentInfo;

public:
    StudentCard();
    StudentCard(const char* _name, const char* _surname, const char* group, const char* _dataIntroduction);
    // add item for this student
    void addItemToStudent(const char* item, int ratirngOfItem);
    // remove item for this student
    void removeItem(const char* item);
    friend ostream& operator<<(ostream& output, const StudentCard& stdCard);
};