/*
 * Name: Dean Farwell
 * Date: 10/02/19
 * Filename: AddressBook.cpp
 * Note: Early Turn-In
 * Description: Function definitions for Addressbook.h
 */

#include "AddressBook.h"
#include <iostream>
#include <fstream>

/*
 * Function: Constructor of Class AddressBook
 * Input: none -- an address book is created, contacts must be added to it later
 * Output: none -- creates a new AddressBook, but nothing is returned by the function
 */
AddressBook::AddressBook() {

}

/*
 * Function: Adds new contacts to the vector m_contacts
 * Input: Contact -- a Contact class, that is constant references, to be added to the address book
 * Output: none -- adds a Contact to the address book, but nothing is returned by the function
 */
void AddressBook::addContact(const Contact &add) {
    m_contacts.push_back(add); // adds a new component to the vector
}

/*
 * Function: Prints out all contacts held within the AddressBook that is called
 * Input: none -- it is a print function, the address book is already known by the function
 * Output: cout -- prints out each Contact within the called AddressBook
 */
void AddressBook::printAllContacts() {
    for (int i = 0; i < m_contacts.size(); i++) { // loops through every contact in the AddressBook vector
        std::cout << m_contacts[i] << std::endl; // prints out each of those contacts
    }
}

/*
 * Function: Returns the number of Contacts within the called AddressBook
 * Input: none
 * Output: int -- some int that is the count of Contacts in the called AddressBook
 */
int AddressBook::size() {
    return m_contacts.size(); // returns the size of the vector
}

/*
 * Function: Deletes all Contacts from the called AddressBook
 * Input: none
 * Output: none -- deletes all Contacts, nothing is returned
 */
void AddressBook::deleteAllContacts() {
    m_contacts.clear(); // deletes all contents of the vector
}

/*
 * Function: Searches the AddressBook for a given Address and returns all contacts that contain that address
 * Inputs: Address -- an Address class, that is constant references, that is used as the search term
 * Output: cout -- prints any Contacts that were found that contained the search Address
 */
void AddressBook::searchByAddress(const Address &search) {
    for (int i = 0; i < m_contacts.size(); i++) { // loops through each contact in the AddressBook
        if (search == m_contacts[i].getAddress()) {
            std::cout << m_contacts[i] << std::endl;
        }
    }
}

/*
 * Function: Reads a file and imports contacts from it
 * Inputs: string -- name of the file for the function to find and open
 * Output: bool -- returns whether or not the function was able to open the file or not
 *         cout -- if the file fails to open, the it will print an error message
 *         none -- otherwise, the function will read the file and add all read contacts to the AddressBook
 */
bool AddressBook::importFromFile(const std::string &fileName) {
    std::ifstream fin(fileName); // opens the file and prepares it for copying

    if (fin.fail()) { // checks if the file fails to open
        std::cout << "Error opening file." << std::endl;
        return false;
    }

    std::string first, last, city, state; // initialize the variables need to pull from the file
    while (fin.good()) { // while there are still contents
        fin >> first >> last >> city >> state; // pulls in the first four data members to be added to a contact
        m_contacts.push_back(Contact(first, last, city, state)); // adds that contact to the AddressBook
    }

    return true;
}