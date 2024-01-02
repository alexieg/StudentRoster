//
//  main.cpp
//  StudentRoster
//
//  Created by Alexie Gordon on 12/10/23.
//

#include <iostream>
#include <string>
#include "roster.hpp"
#include "student.hpp"
using namespace std;


int main() {
    
    const string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Alexie,Gordon,agor176@wgu.edu,25,40,60,45,SOFTWARE"};
    
    cout << "C867 - Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010345094" << endl;
    cout << "Alexie Gordon" << endl;
    
    
    Roster classRoster;
    
    
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }
    
    
    cout << endl;
    cout << "Displaying all students:" << endl;
    cout << endl;
    classRoster.printAll();
    
    cout << endl;
    cout << "Displaying invalid emails:" << endl;
    cout << endl;
    classRoster.printInvalidEmails();
    
    cout << endl;
    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
    }
    
    cout << endl;
    cout << "Showing students in degree program: SOFTWARE" << endl;
    cout << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    
    cout << endl;
    cout << "Removing A3:" << endl;
    cout << endl;
    classRoster.remove("A3");
    
    classRoster.printAll();
    
    cout << endl;
    cout << "Removing A3 again:" << endl;
    cout << endl;
    classRoster.remove("A3");
    
    cout << "DONE." << endl;
    classRoster.~Roster();
}
