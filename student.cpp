//
//  student.cpp
//  StudentRoster
//
//  Created by Alexie Gordon on 12/10/23.
//

#include "student.hpp"
#include <iostream>
#include <string>
using namespace std;

string degreeProgramToString(DegreeProgram degree) {
    //function for finding enum value and converting it to string
    if (degree == DegreeProgram::SECURITY) {
        return "SECURITY";
    }
    else if (degree == DegreeProgram::NETWORK) {
        return "NETWORK";
    }
    else if (degree == DegreeProgram::SOFTWARE) {
        return "SOFTWARE";
    }
    else {
        throw std::invalid_argument("NO DEGREE");
    }
}

string Student::GetStudentID(){
    return studentID;
}

string Student::GetFirstName() {
    return firstName;
}

string Student::GetLastName() {
    return lastName;
}

string Student::GetEmail() {
    return email;
}

int Student::GetAge() {
    return age;
}

int* Student::GetDays() {
    return days;
}

DegreeProgram Student::GetProgram() {
    return degree;
}


void Student::SetStudentId(string studID) {
    studentID = studID;
}

void Student::SetFirstName(string firstname) {
    firstName = firstname;
}

void Student::SetLastName(string lastname) {
    lastName = lastname;
}

void Student::SetEmail(string emailAdd) {
    email = emailAdd;
}

void Student::SetAge(int studentAge) {
    age = studentAge;
}

void Student::SetDays(int day1, int day2, int day3) {
    days[0] = day1;
    days[1] = day2;
    days[2] = day3;
}


void Student::SetProgram(DegreeProgram newDegree) {
    degree = newDegree;
}

void Student::PrintStudentInfo() {
    cout << this->GetStudentID() << "\t";
    cout << this->GetFirstName() << "\t";
    cout << this->GetLastName() << "\t";
    cout << this->GetAge() << "\t";
    
    cout << "{";
    
    for (int i = 0; i < 3; ++i) {
        if (i == 2) {
            cout << days[i];
        }
        else {
            cout << days[i] << ",";
        }
    }
    
    cout << "}" << "\t";
    
    
    cout << degreeProgramToString(this->GetProgram());
    
    cout << endl;
    
}

// Constructor, take in initial data to create student
Student::Student(
    string studentID,
    string firstName,
    string lastName, string emailAddress, int age,
    int day1, int day2, int day3, DegreeProgram degree
                 
) {
    
    this->SetFirstName(firstName);
    this->SetLastName(lastName);
    this->SetStudentId(studentID);
    this->SetEmail(emailAddress);
    this->SetAge(age);
    this->SetDays(day1, day2, day3);
    this->SetProgram(degree);
}

Student::~Student() {
    //days in array memory deleted after creation, not necessary
    //delete[] days;
}
