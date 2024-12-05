#include "notifications.h"
#include "student.h"
#include "instructor.h"
#include <iostream>
using namespace std;

// Constructor
Notification::Notification(const string& id, const string& msg, const string& date)
    : notificationID(id), message(msg), dateSent(date) {}

// Getters
string Notification::getNotificationID() const {
    return notificationID;
}

string Notification::getMessage() const {
    return message;
}

string Notification::getDateSent() const {
    return dateSent;
}

// Broadcast notification to a student
void Notification::broadcastToStudent(const Student& student) const {
    student.sendNotification(message);
}

// Broadcast notification to an instructor
void Notification::broadcastToInstructor(const Instructor& instructor) const {
    instructor.sendNotification(message);
}
