#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Module Class
class Module
{
private:
    string moduleTitle;             // Title of the module
    string moduleID;                // Unique identifier for the module
    vector<string> contentSections; // Sections of content in the module

public:
    // Constructor
    Module(const string &title, const string &id, const vector<string> &sections);

    // Methods
    void displayModuleInfo() const; // Method to display module information

    // Assignment operator
    // This operator allows for the assignment of one Module object to another.
    // It performs a deep copy of the module title, ID, and content sections.
    // Parameters:
    //   const Module& other: The Module object to be copied from.
    // Returns:
    //   A reference to the current Module object.
    Module& operator=(const Module& other);

    // Equality operator
    // This operator checks if two Module objects are equal based on their title and ID.
    // Parameters:
    //   const Module& other: The Module object to compare with.
    // Returns:
    //   true if the modules are equal, false otherwise.
    bool operator==(const Module& other) const;

    // Stream insertion operator
    // This operator outputs the details of the module to the provided output stream.
    // Parameters:
    //   ostream& os: The output stream to write to.
    //   const Module& module: The Module object to output.
    // Returns:
    //   The output stream after writing the module details.
    friend ostream& operator<<(ostream& os, const Module& module);

    // Stream extraction operator
    // This operator reads module details from the input stream into the Module object.
    // Parameters:
    //   istream& is: The input stream to read from.
    //   Module& module: The Module object to populate.
    // Returns:
    //   The input stream after reading the module details.
    friend istream& operator>>(istream& is, Module& module);
};

#endif // MODULE_H