#include "module.h"

int _modules = 0;

// Constructor
Module::Module(const string &title, const string &id, const vector<string> &sections)
    : moduleTitle(title), moduleID(id), contentSections(sections) {}

// Display module information
void Module::displayModuleInfo() const {
    cout << "Module Title: " << moduleTitle << ", Module ID: " << moduleID << endl;
    cout << "Content Sections: ";
    for (const auto& section : contentSections) {
        cout << section << " ";
    }
    cout << endl;
}

// Implement the assignment operator
Module& Module::operator=(const Module& other) {
    if (this != &other) {
        moduleTitle = other.moduleTitle;
        moduleID = other.moduleID;
        contentSections = other.contentSections;
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
    // Assuming contentSections are read in a specific format
    // Additional logic may be needed here
    return is;
}
