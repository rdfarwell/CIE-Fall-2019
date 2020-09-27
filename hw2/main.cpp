/*
 * Name: Dean Farwell
 * Date: 09/16/19
 * Filename: hw2/main.cpp (including Contact.cpp and Contact.h)
 * Note: Early Turn In
 * Description: Homework 2. We are creating a class and utilizing its functions to create Contacts. We then use other functions in the header
 *              to output the contacts or parts of the contacts. Finally, we create a vector of the contacts to form an address book that is
 *              then searched by last name by the user.
 */

#include <iostream>
#include <vector>
#include "Contact.h"

using namespace std;

int main() {

    Contact barry; // 4 Contact creations using the blank Contact constructor and adding each element individually; With 4 uses of setFirstName, setLastName, and setEmailAddress functions
    barry.setFirstName("Barry");
    barry.setLastName("Benson");
    barry.setEmailAddress("barry-b-benson@uiowa.edu");

    Contact connor;
    connor.setFirstName("Connor");
    connor.setLastName("Lichamer");
    connor.setEmailAddress("connor-lichamer@uiowa.edu");

    Contact dean;
    dean.setFirstName("Dean");
    dean.setLastName("Farwell");
    dean.setEmailAddress("dean-farwell@uiowa.edu");

    Contact ron;
    ron.setFirstName("Ron");
    ron.setLastName("Farwell");
    ron.setEmailAddress("ron-farwell@uiowa.edu");

    Contact travis("Travis","Fish", "travis-fish@uiowa.edu"); // 4 Contact creations using a built constructor that adds the first last and email when you create it
    Contact nolan("Nolan", "Peterson", "nolan-peterson@uiowa.edu");
    Contact john("John", "Smith", "john-smith@uiowa.edu");
    Contact karen("Karen", "Pierce", "karen-pierce@uiowa.edu");

    cout << "barry.printLastFirst() should return Benson, Barry (barry-b-benson@uiowa.edu).\nResult = "; // 4 Tests of printLastFirst function
    barry.printLastFirst();
    cout << "connor.printLastFirst() should return Lichamer, Connor (connor-lichamer@uiowa.edu).\nResult = ";
    connor.printLastFirst();
    cout << "travis.printLastFirst() should return Fish, Travis (travis-fish@uiowa.edu).\nResult = ";
    travis.printLastFirst();
    cout << "nolan.printLastFirst() should return Peterson, Nolan (nolan-peterson@uiowa.edu).\nResult = ";
    nolan.printLastFirst();

    cout << endl;

    cout << "dean.printFirstLast() should return Dean, Farwell (dean-farwell@uiowa.edu). \nResult = "; // 4 Tests of printFirstLast function
    dean.printFirstLast();
    cout << "ron.printFirstLast() should return Ron, Farwell (ron-farwell@uiowa.edu). \nResult = ";
    ron.printFirstLast();
    cout << "karen.printFirstLast() should return Karen, Pierce (karen-pierce@uiowa.edu). \nResult = ";
    karen.printFirstLast();
    cout << "john.printFirstLast() should return John, Smith (john-smith@uiowa.edu). \nResult = ";
    john.printFirstLast();

    cout << endl;

    cout << "barry.getFirstName() should return Barry. Result = " << barry.getFirstName() << endl; // 4 Tests of getFirstName function
    cout << "connor.getFirstName() should return Connor. Result = " << connor.getFirstName() << endl;
    cout << "travis.getFirstName() should return Travis. Result = " << travis.getFirstName() << endl;
    cout << "nolan.getFirstName() should return Nolan. Result = " << nolan.getFirstName() << endl;

    cout << endl;

    cout << "barry.getLastName() should return Benson. Result = " << barry.getLastName() << endl; // 4 Tests of getLastName function
    cout << "connor.getLastName() should return Lichamer. Result = " << connor.getLastName() << endl;
    cout << "travis.getLastName() should return Fish. Result = " << travis.getLastName() << endl;
    cout << "dean.getLastName() should return Farwell. Result = " << dean.getLastName() << endl;

    cout << endl;

    cout << "barry.getEmailAddress() should return barry-b-benson@uiowa.edu. Result = " << barry.getEmailAddress() << endl; // 4 Tests of getEmailAddress function
    cout << "connor.getEmailAddress() should return connor-lichamer@uiowa.edu. Result = " << connor.getEmailAddress() << endl;
    cout << "travis.getEmailAddress() should return travis-fish@uiowa.edu. Result = " << travis.getEmailAddress() << endl;
    cout << "ron.getEmailAddress() should return ron-farwell@uiowa.edu. Result = " << ron.getEmailAddress() << endl;

    cout << endl;

    vector<Contact> addressBook; // Creation of the addressBook vector for storing the contacts.
    addressBook.push_back(barry); // Adding all 8 contacts to the vector
    addressBook.push_back(connor);
    addressBook.push_back(dean);
    addressBook.push_back(ron);
    addressBook.push_back(travis);
    addressBook.push_back(nolan);
    addressBook.push_back(john);
    addressBook.push_back(karen);

    int count = 0; // Initializing a counter and response string for user input to search the address book
    string response;
    cout << "Please enter a last name to search by: " << endl;
    getline (cin, response); // Get user input (a last name)

    for (int i = 0; i < addressBook.size(); i++) { // Loop through each element of the addressBook vector
        if (response == addressBook[i].getLastName()) { //  Check if the user input matches any of the last names in the address book
            addressBook[i].printLastFirst(); // Returns any matching contacts
            count++; // Adds 1 to a counter so the program knows we found a match
        }
    }

    if (count == 0) { // If no contacts were found the user gets this message
        cout << "No Contacts found." << endl;
    }


    return 0;
}