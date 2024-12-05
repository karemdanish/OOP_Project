#include "assignment.h"
#include "student.h"
#include "instructor.h"
#include <iostream>
using namespace std;

// Constructor
Assignment::Assignment(const string& assignmentID, const string& description, int maxScore, const string& dueDate)
    : assignmentID(assignmentID), description(description), maxScore(maxScore), dueDate(dueDate) {}

// Submit assignment
void Assignment::submitAssignment(Student* student) {
    submissions.push_back(student);
    cout << student->getName() << " has submitted the assignment: " << assignmentID << endl;
}

// Grade assignment
void Assignment::gradeAssignment(Instructor* instructor, const string& studentID, int score) {
    cout << instructor->getName() << " has graded the assignment " << assignmentID 
         << " for student ID: " << studentID << " with score: " << score << endl;
}

// Implement the assignment operator
Assignment& Assignment::operator=(const Assignment& other) {
    if (this != &other) {
        assignmentID = other.assignmentID;
        description = other.description;
        maxScore = other.maxScore;
        dueDate = other.dueDate;
        submissions = other.submissions; // Assuming deep copy is needed
    }
    return *this;
}

// Implement the equality operator
bool Assignment::operator==(const Assignment& other) const {
    return assignmentID == other.assignmentID && description == other.description 
           && maxScore == other.maxScore && dueDate == other.dueDate;
}

// Implement the stream insertion operator
ostream& operator<<(ostream& os, const Assignment& assignment) {
    os << "Assignment ID: " << assignment.assignmentID << ", Description: " << assignment.description 
       << ", Max Score: " << assignment.maxScore << ", Due Date: " << assignment.dueDate;
    return os;
}

// Implement the stream extraction operator
istream& operator>>(istream& is, Assignment& assignment) {
    is >> assignment.assignmentID >> assignment.description >> assignment.maxScore >> assignment.dueDate;
    return is;
}
