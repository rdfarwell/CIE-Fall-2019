/*
 * Name: Dean Farwell
 * Date: 09/16/19
 * Filename: hw2/Contact.h (used in main.cpp and Contact.cpp)
 * Note: Early Turn In
 * Description: Homework 2. This is the class we created that takes a name and creates a contact. The contact can contain a first name,
 *              last name, and email address. This header file initializes all the functions and variables that are detailed in Contact.cpp
 */

#ifndef HW2_CONTACT_H
#define HW2_CONTACT_H

#include <string>

class Contact {
public:
    Contact(); // Initialize constructors
    Contact(std::string first, std::string last, std::string email);

    void setFirstName(std::string first); // Initialize setter functions
    void setLastName(std::string last);
    void setEmailAddress(std::string email);

    std::string getFirstName() const; // Initialize getter functions
    std::string getLastName() const;
    std::string getEmailAddress() const;

    void printFirstLast(); // Initialize print out functions
    void printLastFirst();
private:
    std::string m_firstName; // Creates the three stored values of this class
    std::string m_lastName;
    std::string m_emailAddress;
};
#endif //HW2_CONTACT_H
