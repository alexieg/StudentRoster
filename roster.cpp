//
//  roster.cpp
//  StudentRoster
//
//  Created by Alexie Gordon on 12/10/23.
//

#include "roster.hpp"
#include <iostream>
#include <string>
using namespace std;



DegreeProgram stringToDegreeProgram(string strDegree) {
    //function for returning a string degree to the enum value
    if (strDegree == "SECURITY") {
        return DegreeProgram::SECURITY;
    }
    else if (strDegree == "NETWORK") {
        return DegreeProgram::NETWORK;
    }
    else if (strDegree == "SOFTWARE") {
        return DegreeProgram::SOFTWARE;
    }
    else {
        throw std::invalid_argument("INVALID DEGREE");
    }
}

void Roster::add(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress, int age,
    int day1,
    int day2,
    int day3,
    DegreeProgram degree
) {
    
    Student* addStudent = new Student(studentID, firstName, lastName, emailAddress, age, day1, day2, day3, degree);
    
    //find the next empty index and insert new student
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = addStudent;
            break;
        }
    }

}

void Roster::remove(string studentID) {
    //check for matching ID, remove the student
    //if ID does not exist, return error
    bool didRemove = false;
    for (int i = 0; i < 5; ++i) {
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->GetStudentID() == studentID)) {
            classRosterArray[i] = nullptr;
            didRemove = true;
            break;
        }
        
    }
    //if we didnt find, error
    if (didRemove == false) {
        cout << "The student with the ID: " << studentID << " was not found." << endl;
    }
}

void Roster::printAll() {
    //iterate over array and print each student
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->PrintStudentInfo();
        }
    }
    
}

void Roster::printAverageDaysInCourse(string studentID) {
    //check for null, check for matching ID, average the days in the array
    for (int i = 0; i < 5; ++i) {
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->GetStudentID() == studentID)) {
            Student* student = classRosterArray[i];
            int* days = student->GetDays();
            float average = (days[0] + days[1] + days[2]) / 3;
            cout << "Student ID: " << studentID << ", average days in course is: ";
            cout << average << endl;
            break;
        }
        
    }
}

void Roster::printInvalidEmails() {
    //check if student has a valid email, assign validEmail to true
    bool validEmail = false;
    for (int i = 0; i < 5; ++i) {
        string email = classRosterArray[i]->GetEmail();
        size_t searchValid = email.find("@");
        if (searchValid != string::npos) {
            searchValid = email.find(".");
            if (searchValid != string::npos) {
                searchValid = email.find(" ");
                if (searchValid == string::npos) {
                    validEmail = true;
                }
            }
        }
        if (validEmail == false) {
            cout << email << " - is invalid." << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
    //check for null values, check for matching degree, print degree
    for (int i = 0; i < 5; ++i) {
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->GetProgram() == degree)) {
            Student* student = classRosterArray[i];
            student->PrintStudentInfo();
        }
        
    }
}

void Roster::parse(string row) {
    size_t rhs = row.find(",");
    string studentID = row.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string firstName = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string lastName = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int age = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int day1 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int day2 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int day3 = stoi(row.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string strDegree = row.substr(lhs, rhs - lhs);
    
    
    this->add(studentID, firstName, lastName, emailAddress, age, day1, day2, day3, stringToDegreeProgram(strDegree));
    
    
}

Roster::~Roster() {
    //memory deleted after creation, not necessary
    //delete[] classRosterArray;
}
