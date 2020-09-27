/*
 * Name: Dean Farwell
 * Date: 09/16/19
 * Filename: hw2/Contact.cpp (Including main.cpp and Contact.h)
 * Note: Early Turn In
 * Description: Homework 2. This file gives definitions to each function initialized in Contact.h
 */

#include "Contact.h"
#include <iostream>

/*
 * Function: Default constructor (creates a named Contact that contains no arguments)
 * Input: none
 * Outputs: none
 */
Contact::Contact() {
    /*
     * We do not need to initialize anything within this constructor as it has no issue creating a name without any arguments.
     * Therefore, it will create the new subclass, but all strings will be empty until they are edited. The other constructor skips
     * these steps by taking in all three arguments when it is created.
     */
}

/*
 * Function: Constructor that sets the first name, last name, and email address when it is created
 * Input: string -- first (any first name), last (any last name), and email (any email address)
 * Output: none
 */
Contact::Contact(std::string first, std::string last, std::string email) {
    setFirstName(first);
    setLastName(last);
    setEmailAddress(email);
}

/*
 * Function: Sets the first name of a Contact class
 * Input: string -- first (any first name)
 * Output: none
 */
void Contact::setFirstName(std::string first) {
    m_firstName = first;
}

/*
 * Function: Sets the last name of a Contact class
 * Input: string -- last (any last name)
 * Output: none
 */
void Contact::setLastName(std::string last) {
    m_lastName = last;
}

/*
 * Function: Sets the email address of a Contact class
 * Input: string -- email (any email address)
 * Output: none
 */
void Contact::setEmailAddress(std::string email) {
    m_emailAddress = email;
}

/*
 * Function: Returns the first name of a given Contact class
 * Input: none
 * Output: string -- first name stored in called contact
 */
std::string Contact::getFirstName() const {
    return m_firstName;
}

/*
 * Function: Returns the last name of a given Contact class
 * Input: none
 * Output: string -- last name stored in called contact
 */
std::string Contact::getLastName() const {
    return m_lastName;
}

/*
 * Function: Returns the email address of a given Contact class
 * Input: none
 * Output: string -- email address stored in called contact
 */
std::string Contact::getEmailAddress() const {
    return m_emailAddress;
}

/*
 * Function: prints out the contact in a first name, last name format with email (first, last (email))
 * Input: none
 * Output: void -- the function itself does not return anything
 *         cout -- prints out "first, last (email)"
 */
void Contact::printFirstLast() {
    std::cout << getFirstName() << ", " << getLastName() << " (" << getEmailAddress() << ")" << std::endl;
}

/*
 * Function: prints out the contact in a last name, first name format with email (last, first (email))
 * Input: none
 * Output: void -- the function itself does not return anything
 *         cout -- prints out "last, first (email)"
 */
void Contact::printLastFirst() {
    std::cout << getLastName() << ", " << getFirstName() << " (" << getEmailAddress() << ")" << std::endl;
}
