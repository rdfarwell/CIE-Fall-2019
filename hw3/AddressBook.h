/*
 * Name: Dean Farwell
 * Date: 10/02/19
 * Filename: AddressBook.h
 * Note: Early Turn-In
 * Description: Function declarations for created class AddressBook
 */
#ifndef HW3_ADDRESSBOOK_H
#define HW3_ADDRESSBOOK_H

#include <vector>
#include <string>
#include "Contact.h"
#include "Address.h"

class AddressBook {
public:
    AddressBook(); // Default constructor

    void addContact(const Contact &add); // adds contacts to AddressBook

    void printAllContacts(); // prints all listed contacts
    int size(); // gives size of AddressBook
    void deleteAllContacts(); // deletes all contents of AddressBook

    void searchByAddress(const Address &search); // search functions

    bool importFromFile(const std::string &fileName); // imports contacts from a file

private:
    std::vector<Contact> m_contacts; // initialization of the class's variable
};


#endif //HW3_ADDRESSBOOK_H
