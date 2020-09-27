/*
 * Name: Dean Farwell
 * Date: 10/02/19
 * Filename: hw3/main.cpp (uses Contact.h/.cpp, Address.h/.cpp, AddressBook.h/.cpp, and input.txt)
 * Note: Early Turn-In
 * Description: A program that uses three different classes to create an address book of contacts, in which each contact
 *              contains a first and last name, along with an address. the address contains a city and a state. The
 *              address book can then be searched for a specific address, check its size, and clear it out. Finally, it
 *              can read in a file to create a new address book.
 */

#include <iostream>
#include "Address.h"
#include "Contact.h"
#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook book; // Creation of address book

    Contact rick; // Creation of contact rick with only first name passed
    rick.setFirstName("Rick"); // sets Contact rick's first name as Rick
    rick.setLastName("Astley"); // adds last name to contact rick
    Address newYork; // Creation of address newYork
    newYork.setCity("New York");
    newYork.setState("New York");
    rick.setAddress(newYork); // adds newYork address as rick's address
    book.addContact(rick); // adds rick to address book

    Contact ron("Ron"); // Creation of contact ron
    ron.setLastName("Farwell"); // Adds last name to Contact ron
    Address orion("Orion"); // Creation of an Address class with only a city
    orion.setState("Illinois"); //  adds specific state to created Address orion
    ron.setAddress(orion); // sets ron's address as Address orion
    book.addContact(ron); // adds ron to address book

    Contact dean("Dean", "Farwell", "Orion", "Illinois");  // Creation of contact dean using shortest possible constructor
    book.addContact(dean); // adds dean to address book

    Contact anakin("Anakin", "Skywalker", "Tatooine"); // Creation of contact anakin
    book.addContact(anakin); // adds anakin to address book

    cout << "Number of contacts in address book (should print 4): " << book.size() << endl; // Test of size function
    cout << endl;

    cout << "First name of contact dean (should return Dean): " << dean.getFirstName() << endl; // Test of getFirstName function
    cout << "Last name of contact anakin (should return Skywalker): " << anakin.getLastName() << endl; // Test of getLastName function
    cout << endl;

    cout << "Print all contacts should result in:\n\nRick Astley\nNew York, New York\n\nRon Farwell\nOrion, Illinois\n\nDean Farwell\nOrion, Illinois\n\nAnakin Skywalker\nTatooine,\n" << endl;
    cout << "Print all contacts:\n" << endl; // Test of printAllContacts function
    book.printAllContacts();

    cout << "Search results for address " << orion << " should return Ron and Dean's Contacts" << endl; // Test of searchByAddress function
    book.searchByAddress(orion);

    cout << "Deleting all contacts..." << endl; // Test of deleteAllContacts function
    book.deleteAllContacts();
    cout << "Number of contacts in address book (Should be 0): " << book.size() << endl; // Proof of deleteAllContacts

    cout << "Importing contacts..." << endl;
    book.importFromFile("input.txt"); // Test of importFromFile function, imports new contacts

    cout << "Number of contacts in address book (should print 2): " << book.size() << endl; // Check that contacts were read in
    cout << endl;

    cout << "Print all components in book: " << endl; // Shows the imported Contacts
    book.printAllContacts();

    return 0;
}