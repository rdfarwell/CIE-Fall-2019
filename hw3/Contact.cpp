/*
 * Name: Dean Farwell
 * Date: 10/02/19
 * Filename: Contact.cpp
 * Note: Early Turn-In
 * Description: Function definitions for Contact.h
 */

#include "Contact.h"

/*
 * Function: Constructor of Class Contact
 * Inputs: Four strings -- four strings, first, last, city and state, that are constant references; used to set m_firstname, m_lastname, and m_address of the class
 * Output: none -- creates a new Contact, but nothing is returned by the function
 */
Contact::Contact(const std::string &first, const std::string &last, const std::string &city, const std::string &state)
    : m_firstName{first}, m_lastName{last}, m_address{city, state} {

}

void Contact::setFirstName(const std::string &first) {
    m_firstName = first;
}

void Contact::setLastName(const std::string &last) {
    m_lastName = last;
}

void Contact::setAddress(const Address &set) {
    m_address = set;
}

const std::string &Contact::getFirstName() const {
    return m_firstName;
}

const std::string &Contact::getLastName() const {
    return m_lastName;
}

const Address &Contact::getAddress() const {
    return m_address;
}

/*
 * Function: Overrides the << operator so we can output a contact without calling each of its individual components
 * Inputs: ostream -- an output type that allows the function to be printed and returned
 *         Contact -- a contact class, that is constant references, that is formatted to be output as individual components
 * Output: ostream -- the converted Contact is returned in the desired printing format
 */
std::ostream &operator<<(std::ostream &output, const Contact &contact) {
    output << contact.m_firstName << " " << contact.m_lastName << "\n" << contact.m_address << std::endl; // separates the Contact for output
    return output;
}

/*
 * Function: Overrides the == operator so we can check if two Contacts are the same without calls to each of their individual components
 * Inputs: Contact -- two Contact classes, that are constant references, to be compared to see if they are the same
 * Output: bool -- returns if the given Contacts are the same or not as a boolean
 */
bool operator==(Contact &c1, Contact &c2) {
    return (c1.m_firstName == c2.m_firstName) && (c1.m_lastName == c2.m_lastName) && (c1.m_address == c2.m_address); // separates the Contact for comparison
}