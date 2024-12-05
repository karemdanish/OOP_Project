#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <string>
#include <vector>
using namespace std;

class Student; // Forward declaration
class Instructor; // Forward declaration

class Notification {
private:
    string notificationID; // Unique identifier for the notification
    string message;        // Notification message
    string dateSent;      // Date when the notification was sent

public:
    // Constructor
    Notification(const string& id, const string& msg, const string& date);

    // Getters
    string getNotificationID() const;
    string getMessage() const;
    string getDateSent() const;

    // Method to broadcast notification to a student
    void broadcastToStudent(const Student& student) const;

    // Method to broadcast notification to an instructor
    void broadcastToInstructor(const Instructor& instructor) const;
};

#endif // NOTIFICATIONS_H
