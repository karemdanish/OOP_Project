#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <vector>
#include <string>
#include "notifications.h"
using namespace std;

// Derived Class
// The Student class inherits from the Person class, adding specific attributes and methods
// related to students in the system.
class Student : public Person {
private:
    string studentID;               // Unique identifier for the student
    string enrollmentDate;          // Date the student enrolled
    vector<string> completedCourses; // List of courses completed by the student

public:
    // Constructor
    Student(const string& name, const string& ID, const string& email, const string& studentID, const string& enrollmentDate);

    // Copy assignment operator declaration
    Student &operator=(const Student &other);
    
    // This method displays the student's information, including their name, ID, email, student ID, and enrollment date.
    void displayInfo() const; 

    // Override getRole
    string getRole() const; 

    // This method sends a notification message to the student.
    void sendNotification(const string& message) const;     

    // Equality operator
    // This operator checks if two Student objects are equal based on their attributes.
    // Parameters:
    //   const Student& other: The Student object to compare with.
    // Returns:
    //   true if the students are equal, false otherwise.
    bool operator==(const Student& other) const;

    // Stream insertion operator
    // This operator outputs the details of the student to the provided output stream.
    // Parameters:
    //   ostream& os: The output stream to write to.
    //   const Student& student: The Student object to output.
    // Returns:
    //   The output stream after writing the student details.
    friend ostream& operator<<(ostream& os, const Student& student);

    // Stream extraction operator
    // This operator reads student details from the input stream into the Student object.
    // Parameters:
    //   istream& is: The input stream to read from.
    //   Student& student: The Student object to populate.
    // Returns:
    //   The input stream after reading the student details.
    friend istream& operator>>(istream& is, Student& student);

    // Subscript operator
    // This operator allows access to completed courses by index.
    // Parameters:
    //   int index: The index of the completed course to access.
    // Returns:
    //   A reference to the completed course at the specified index.
    string& operator[](int index);

    // Add course
    // This operator adds a course to the student's completed courses.
    // Parameters:
    //   const string& course: The course to add.
    // Returns:
    //   A reference to the current Student object.
    Student& operator+(const string& course);

    // Remove course
    // This operator removes a course from the student's completed courses.
    // Parameters:
    //   const string& course: The course to remove.
    // Returns:
    //   A reference to the current Student object.
    Student& operator-(const string& course);

    // Union of courses
    // This operator returns a vector of courses that are in either student.
    // Parameters:
    //   const Student& other: The other student to compare with.
    // Returns:
    //   A vector of strings representing the union of courses.
    vector<string> operator|(const Student& other) const;

    // Intersection of courses
    // This operator returns a vector of courses that are in both students.
    // Parameters:
    //   const Student& other: The other student to compare with.
    // Returns:
    //   A vector of strings representing the intersection of courses.
    vector<string> operator&(const Student& other) const;

    void enrollInCourse(const string& course);
    void submitAssignment(const string& assignment);
    void checkProgress() const;
    void viewCertifications() const;
    void receiveNotification(const Notification& notification);

    virtual ~Student() {} // Virtual destructor
};

#endif //STUDENT_H
