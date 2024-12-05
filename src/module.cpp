#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Module Class
class Module {
private:
    string moduleTitle;      // Title of the module
    string moduleID;         // Unique identifier for the module
    vector<string> contentSections; // Sections of content in the module

public:
    // Constructor
    Module(const string& title, const string& id, const vector<string>& sections);

    // Methods
    void displayModuleInfo() const; // Method to display module information

    // Implement the assignment operator
    Module& operator=(const Module& other);

    // Implement the equality operator
    bool operator==(const Module& other) const;

    // Implement the stream insertion operator
    friend ostream& operator<<(ostream& os, const Module& module);

    // Implement the stream extraction operator
    friend istream& operator>>(istream& is, Module& module);
};

// Constructor
Module::Module(const string& title, const string& id, const vector<string>& sections) 
    : moduleTitle(title), moduleID(id), contentSections(sections) {
    // Constructor body (if needed)
}

void Module::displayModuleInfo() const {
    // Display the module information
    cout << "Module Title: " << moduleTitle << endl;
    cout << "Module ID: " << moduleID << endl;
    cout << "Content Sections: " << endl;
    for (const auto& section : contentSections) {
        cout << "- " << section << endl;
    }
}

// Implement the assignment operator
Module& Module::operator=(const Module& other) {
    if (this != &other) {
        moduleTitle = other.moduleTitle;
        moduleID = other.moduleID;
        contentSections = other.contentSections; // Assuming deep copy is needed
    }
    return *this;
}

// Implement the equality operator
bool Module::operator==(const Module& other) const {
    return moduleTitle == other.moduleTitle && moduleID == other.moduleID;
}

// Implement the stream insertion operator
ostream& operator<<(ostream& os, const Module& module) {
    os << "Module Title: " << module.moduleTitle << ", Module ID: " << module.moduleID;
    return os;
}

// Implement the stream extraction operator
istream& operator>>(istream& is, Module& module) {
    is >> module.moduleTitle >> module.moduleID;
    return is;
}

#endif // MODULE_H
