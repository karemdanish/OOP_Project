#include <iostream>
#include <vector>
#include "student.h"
#include "instructor.h"
#include "admin.h"
#include "course.h"
#include "assignment.h"
#include "notifications.h"
#include "group.h"

using namespace std;

void displayMenu() {
    cout << "Welcome to the Project Management System!" << endl;
    cout << "1. Student" << endl;
    cout << "2. Instructor" << endl;
    cout << "3. Admin" << endl;
    cout << "4. Exit" << endl;
    cout << "Select your role: ";
}

void studentMenu(Student& student) {
    int choice;
    do {
        cout << "\nStudent Menu:" << endl;
        cout << "1. Display Info" << endl;
        cout << "2. Enroll in Course" << endl;
        cout << "3. Submit Assignment" << endl;
        cout << "4. Check Progress" << endl;
        cout << "5. Receive Notification" << endl;
        cout << "6. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                student.displayInfo();
                break;
            case 2: {
                string course;
                cout << "Enter course name to enroll: ";
                cin >> course;
                student.enrollInCourse(course);
                break;
            }
            case 3: {
                string assignment;
                cout << "Enter assignment name to submit: ";
                cin >> assignment;
                student.submitAssignment(assignment);
                break;
            }
            case 4:
                student.checkProgress();
                break;
            case 5: {
                Notification notification("1", "You have a new message!", "2023-10-01");
                student.receiveNotification(notification);
                break;
            }
            case 6:
                cout << "Exiting Student Menu." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 6);
}

void instructorMenu(Instructor& instructor) {
    int choice;
    do {
        cout << "\nInstructor Menu:" << endl;
        cout << "1. Display Info" << endl;
        cout << "2. Create Assignment" << endl;
        cout << "3. Grade Submission" << endl;
        cout << "4. Monitor Student Progress" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                instructor.displayInfo();
                break;
            case 2: {
                string assignment;
                cout << "Enter assignment name to create: ";
                cin >> assignment;
                instructor.createAssignment(assignment);
                break;
            }
            case 3: {
                string submission;
                cout << "Enter submission to grade: ";
                cin >> submission;
                instructor.gradeSubmission(submission);
                break;
            }
            case 4:
                instructor.monitorStudentProgress();
                break;
            case 5:
                cout << "Exiting Instructor Menu." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);
}

void adminMenu(Admin& admin) {
    int choice;
    do {
        cout << "\nAdmin Menu:" << endl;
        cout << "1. Display Info" << endl;
        cout << "2. Add Course" << endl;
        cout << "3. Remove Course" << endl;
        cout << "4. Generate Reports" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                admin.displayInfo();
                break;
            case 2: {
                string course;
                cout << "Enter course name to add: ";
                cin >> course;
                admin.addCourse(course);
                break;
            }
            case 3: {
                string course;
                cout << "Enter course name to remove: ";
                cin >> course;
                admin.removeCourse(course);
                break;
            }
            case 4:
                admin.generateReports();
                break;
            case 5:
                cout << "Exiting Admin Menu." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);
}

int main() {
    int role;
    do {
        displayMenu();
        cin >> role;

        switch (role) {
            case 1: {
                Student student("John Doe", "S123", "john@example.com", "STU001", "2023-09-01");
                studentMenu(student);
                break;
            }
            case 2: {
                Instructor instructor("Jane Smith", "I456", "jane@example.com", "EMP001", "Computer Science");
                instructorMenu(instructor);
                break;
            }
            case 3: {
                vector<string> permissions;
                permissions.push_back("Manage Courses");
                permissions.push_back("Generate Reports");
                Admin admin("Admin User", "A789", "admin@example.com", "ADMIN001", permissions, "Administration");
                adminMenu(admin);
                break;
            }
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid role. Please try again." << endl;
        }
    } while (role != 4);

    return 0;
}
