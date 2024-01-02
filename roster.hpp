//
//  roster.hpp
//  StudentRoster
//
//  Created by Alexie Gordon on 12/10/23.
//

#ifndef roster_hpp
#define roster_hpp

#include "student.hpp"

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class Roster {
    public:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degree);
    void parse(string);
    Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    ~Roster();
};




#endif /* roster_hpp */
