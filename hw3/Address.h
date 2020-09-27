/*
 * Name: Dean Farwell
 * Date: 10/02/19
 * Filename: Address.h
 * Note: Early Turn-In
 * Description: Function declarations for created class Address
 */

#ifndef HW3_ADDRESS_H
#define HW3_ADDRESS_H

#include <string>
#include <iostream>

class Address {
public:
    Address(const std::string &city = "", const std::string &state = ""); // Constructor with default empty string values

    void setCity(const std::string &city); // setters
    void setState(const std::string &state);

    const std::string &getCity() const; // getters
    const std::string &getState() const;

    friend std::ostream &operator<<(std::ostream &output, const Address &address); // friends
    friend bool operator==(const Address &a1, const Address &a2);

private:
    std::string m_city; // initialization of the class's variables
    std::string m_state;
};


#endif //HW3_ADDRESS_H
