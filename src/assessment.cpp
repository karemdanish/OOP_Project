#include "assessment.h"
#include <iostream>
using namespace std;

// Constructor
Assessment::Assessment(const string& assessmentID, const string& assessmentType, int totalMarks)
    : assessmentID(assessmentID), assessmentType(assessmentType), totalMarks(totalMarks) {}

// Method for students to take the assessment
void Assessment::takeAssessment(const string& studentID, int score) {
    studentScores.push_back(studentID + ": " + to_string(score));
    cout << "Student " << studentID << " has taken the assessment with score: " << score << endl;
}

// Method to view scores
void Assessment::viewScores() const {
    cout << "Scores for Assessment " << assessmentID << " (" << assessmentType << "):" << endl;
    for (const auto& score : studentScores) {
        cout << score << endl;
    }
}

// Implement the assignment operator
Assessment& Assessment::operator=(const Assessment& other) {
    if (this != &other) {
        assessmentID = other.assessmentID;
        assessmentType = other.assessmentType;
        totalMarks = other.totalMarks;
        studentScores = other.studentScores; // Assuming deep copy is needed
    }
    return *this;
}

// Implement the equality operator
bool Assessment::operator==(const Assessment& other) const {
    return assessmentID == other.assessmentID && assessmentType == other.assessmentType 
           && totalMarks == other.totalMarks;
}

// Implement the stream insertion operator
ostream& operator<<(ostream& os, const Assessment& assessment) {
    os << "Assessment ID: " << assessment.assessmentID << ", Type: " << assessment.assessmentType 
       << ", Total Marks: " << assessment.totalMarks;
    return os;
}

// Implement the stream extraction operator
istream& operator>>(istream& is, Assessment& assessment) {
    is >> assessment.assessmentID >> assessment.assessmentType >> assessment.totalMarks;
    return is;
}
