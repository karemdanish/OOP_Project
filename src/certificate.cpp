#include "certificate.h"
#include "course.h"
#include "student.h"
#include <iostream>
using namespace std;

// Constructor
Certificate::Certificate(const string& certID, const string& date, const string& title, const string& recipient, Course* course, Student* student)
    : certificateID(certID), issueDate(date), courseTitle(title), recipient(recipient), course(course), student(student) {}

// Display certificate information
void Certificate::displayCertificateInfo() const {
    cout << "Certificate ID: " << certificateID << ", Issue Date: " << issueDate 
         << ", Course Title: " << courseTitle << ", Recipient: " << recipient << endl;
}

// Implement the assignment operator
Certificate& Certificate::operator=(const Certificate& other) {
    if (this != &other) {
        certificateID = other.certificateID;
        issueDate = other.issueDate;
        courseTitle = other.courseTitle;
        recipient = other.recipient;
        course = other.course; // Assuming deep copy is needed
        student = other.student; // Assuming deep copy is needed
    }
    return *this;
}

// Implement the equality operator
// This operator checks if two Certificate objects are equal based on their ID, issue date, course title, and recipient.
// Parameters:
//   const Certificate& other: The Certificate object to compare with.
// Returns:
//   true if the certificates are equal, false otherwise.
bool Certificate::operator==(const Certificate& other) const {
    return certificateID == other.certificateID && issueDate == other.issueDate 
           && courseTitle == other.courseTitle && recipient == other.recipient;
}

// Implement the stream insertion operator
// This operator outputs the details of the certificate to the provided output stream.
// Parameters:
//   ostream& os: The output stream to write to.
//   const Certificate& certificate: The Certificate object to output.
// Returns:
//   The output stream after writing the certificate details.
ostream& operator<<(ostream& os, const Certificate& certificate) {
    os << "Certificate ID: " << certificate.certificateID << ", Issue Date: " << certificate.issueDate 
       << ", Course Title: " << certificate.courseTitle << ", Recipient: " << certificate.recipient;
    return os;
}

// Implement the stream extraction operator
// This operator reads certificate details from the input stream into the Certificate object.
// Parameters:
//   istream& is: The input stream to read from.
//   Certificate& certificate: The Certificate object to populate.
// Returns:
//   The input stream after reading the certificate details.
istream& operator>>(istream& is, Certificate& certificate) {
    is >> certificate.certificateID >> certificate.issueDate >> certificate.courseTitle >> certificate.recipient;
    return is;
}
