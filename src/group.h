#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Group Class
class Group {
private:
    static string groupID; // Static group identifier, shared across all instances
    static vector<string> members; // Static list of group members, shared across all instances

public:
    // Static functions to manage the group
    // This method creates a new group with the specified ID.
    // Parameters:
    //   const string& id: The ID for the new group.
    static void createGroup(const string& id);

    // This method adds a member to the group.
    // Parameters:
    //   const string& member: The member to add to the group.
    static void addMember(const string& member);

    // This method removes a member from the group.
    // Parameters:
    //   const string& member: The member to remove from the group.
    static void removeMember(const string& member);

    // This method displays information about the group.
    static void displayGroupInfo(); // Display the group's ID and members
};

#endif // GROUP_H
