#include "StudentCard.h"

StudentCard::StudentInfo::StudentInfo() {}

StudentCard::StudentInfo::StudentInfo(int size)
    : listOfLection{new string[size]}, rating{new int[size]}, numberOfItems{0}, maxListOfItem{30}
{
}

void StudentCard::StudentInfo::addItem(const char* item, int ratingItem)
{
    if (listOfLection == nullptr)
        return;

    if (numberOfItems + 1 == maxListOfItem) {
        string* tmpList = new string[maxListOfItem + 1];
        int* tmpRating = new int[maxListOfItem + 1];
        for (int i = 0; i < maxListOfItem; i++) {
            tmpList[i] = listOfLection[i];
            tmpRating[i] = rating[i];
        }

        tmpList[maxListOfItem - 1] = item;
        tmpRating[maxListOfItem - 1] = ratingItem;

        delete[] listOfLection;
        delete[] rating;
        listOfLection = tmpList;
        rating = tmpRating;
        tmpList = nullptr;
        tmpRating = nullptr;
        maxListOfItem++;
        numberOfItems++;
    }

    else {
        listOfLection[numberOfItems] = item;
        rating[numberOfItems] = ratingItem;
        numberOfItems++;
    }
}

void StudentCard::StudentInfo::removeItem(const char* item)
{
    int index = 0;
    for (int i = 0; i < numberOfItems; i++) {
        if (listOfLection[i] == item) {
            index = i;
            break;
        }
    }

    for (int i = index; i < numberOfItems; i++) {
        listOfLection[i] = listOfLection[i + 1];
        rating[i] = rating[i + 1];
    }

    numberOfItems--;
}

StudentCard::StudentInfo::~StudentInfo()
{
    delete[] listOfLection;
    delete[] rating;
    numberOfItems = 0;
    maxListOfItem = 0;
}

StudentCard::StudentCard() {}

StudentCard::StudentCard(const char* _name, const char* _surname, const char* group, const char* _dataIntroduction)
    : name{_name}, surname{_surname}, groupName{group}, dataIntroduction{_dataIntroduction}, studentInfo{6}
{
}

void StudentCard::addItemToStudent(const char* item, int ratirngOfItem)
{
    studentInfo.addItem(item, ratirngOfItem);
}

void StudentCard::removeItem(const char* item)
{
    studentInfo.removeItem(item);
}

ostream& operator<<(ostream& output, const StudentCard& stdCard)
{
    cout << "Name: " << stdCard.name << "\n"
         << "Surname: " << stdCard.surname << "\n"
         << "Group: " << stdCard.groupName << "\n"
         << "Data introduction: " << stdCard.dataIntroduction << "\n\t" << stdCard.studentInfo;

    return output;
}
