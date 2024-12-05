#ifndef ASSESSMENT_H
#define ASSESSMENT_H

#include <string>
#include <vector>
using namespace std;

// Assessment Class
class Assessment {
private:
    string assessmentID;      // Unique identifier for the assessment
    string assessmentType;    // Type of assessment (e.g., exam, quiz)
    int totalMarks;           // Total marks for the assessment
    vector<string> studentScores; // Scores of students for this assessment

public:
    // Constructor
    Assessment(const string& assessmentID, const string& assessmentType, int totalMarks);

    // Method for students to take the assessment
    void takeAssessment(const string& studentID, int score); // Record a student's score for the assessment

    // Method to view scores
    void viewScores() const; // Display the scores of students for this assessment

    // Assignment operator
    // This operator allows for the assignment of one Assessment object to another.
    // It performs a deep copy of the assessment ID, type, total marks, and student scores.
    // Parameters:
    //   const Assessment& other: The Assessment object to be copied from.
    // Returns:
    //   A reference to the current Assessment object.
    Assessment& operator=(const Assessment& other);

    // Equality operator
    // This operator checks if two Assessment objects are equal based on their ID, type, total marks, and scores.
    // Parameters:
    //   const Assessment& other: The Assessment object to compare with.
    // Returns:
    //   true if the assessments are equal, false otherwise.
    bool operator==(const Assessment& other) const;

    // Stream insertion operator
    // This operator outputs the details of the assessment to the provided output stream.
    // Parameters:
    //   ostream& os: The output stream to write to.
    //   const Assessment& assessment: The Assessment object to output.
    // Returns:
    //   The output stream after writing the assessment details.
    friend ostream& operator<<(ostream& os, const Assessment& assessment);

    // Stream extraction operator
    // This operator reads assessment details from the input stream into the Assessment object.
    // Parameters:
    //   istream& is: The input stream to read from.
    //   Assessment& assessment: The Assessment object to populate.
    // Returns:
    //   The input stream after reading the assessment details.
    friend istream& operator>>(istream& is, Assessment& assessment);
};

#endif //ASSESSMENT_H
