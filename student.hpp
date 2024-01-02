//
//  student.hpp
//  StudentRoster
//
//  Created by Alexie Gordon on 12/10/23.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include "degree.h"

#include <iostream>
#include <string>
using namespace std;



class Student {
    public:
    
    //accessors
    string GetStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmail();
    int GetAge();
    int* GetDays();
    DegreeProgram GetProgram();
    
    //constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int day1, int day2, int day3, DegreeProgram degree);
    
    //deconstructor
    ~Student();
    
    //mutators
    void SetStudentId(string studentID);
    void SetFirstName(string firstname);
    void SetLastName(string lastname);
    void SetEmail(string emailAdd);
    void SetAge(int studentAge);
    void SetDays(int day1, int day2, int day3);
    void SetProgram(DegreeProgram degree);
    void PrintStudentInfo();
    
    
    
    private:
    
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    DegreeProgram degree;
    int days[3];
    
};


#endif /* student_hpp */
