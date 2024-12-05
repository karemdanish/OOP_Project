#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include <vector>
using namespace std;

// Forward declarations
class Student;
class Instructor;

// Assignment Class
class Assignment {
private:
    string assignmentID;      // Unique identifier for the assignment
    string description;       // Description of the assignment
    int maxScore;             // Maximum score for the assignment
    string dueDate;           // Due date for the assignment
    vector<Student*> submissions; // List of students who submitted the assignment

public:
    // Constructor
    Assignment(const string& assignmentID, const string& description, int maxScore, const string& dueDate);

    // Method to submit assignment
    void submitAssignment(Student* student);

    // Method to grade assignment
    void gradeAssignment(Instructor* instructor, const string& studentID, int score);

    // Assignment operator
    Assignment& operator=(const Assignment& other);

    // Equality operator
    bool operator==(const Assignment& other) const;

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Assignment& assignment);

    // Stream extraction operator
    friend istream& operator>>(istream& is, Assignment& assignment);
};

#endif // ASSIGNMENT_H
