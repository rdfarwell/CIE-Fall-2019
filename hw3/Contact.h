/*
 * Name: Dean Farwell
 * Date: 10/02/19
 * Filename: Contact.h
 * Note: Early Turn-In
 * Description: Function declarations for created class Contact
 */

#ifndef HW3_CONTACT_H
#define HW3_CONTACT_H

#include <string>
#include "Address.h"

class Contact {
public:
    Contact(const std::string &first = "", const std::string &last = "", const std::string &city = "", const std::string &state = ""); // Constructor with default empty strings

    void setFirstName(const std::string &first); // Setter Functions
    void setLastName(const std::string &last);
    void setAddress(const Address &set);

    const std::string &getFirstName() const; // Getter functions
    const std::string &getLastName() const;
    const Address &getAddress() const;

    friend std::ostream &operator<<(std::ostream &output, const Contact &contact); // friends
    friend bool operator==(Contact &c1, Contact &c2);

private:
    std::string m_firstName; // initialization of the class's variables
    std::string m_lastName;
    Address m_address;
};


#endif //HW3_CONTACT_H
