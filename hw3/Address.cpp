/*
 * Name: Dean Farwell
 * Date: 10/02/19
 * Filename: Address.cpp
 * Note: Early Turn-In
 * Description: Function definitions for Address.h
 */

#include "Address.h"
/*
 * Function: Constructor of Class Address
 * Inputs: Two strings -- two strings, city and state, that are constant references; used to set m_city and m_state of class
 * Output: none -- creates a new Address, but nothing is returned by the function
 */
Address::Address(const std::string &city, const std::string &state) : m_city{city}, m_state{state} {

}

void Address::setCity(const std::string &city) {
    m_city = city;
}

void Address::setState(const std::string &state) {
    m_state = state;
}

const std::string &Address::getCity() const {
    return m_city;
}

const std::string &Address::getState() const {
    return m_state;
}

/*
 * Function: Overrides the << operator so we can output an address without calling each of its individual components
 * Inputs: ostream -- an output type that allows the function to be printed and returned
 *         Address -- an Address class, that is constant references, that is formatted to be output as individual components
 * Output: ostream -- the converted Address is returned in the desired printing format
 */
std::ostream &operator<<(std::ostream &output, const Address &address) {
    output << address.m_city << ", " << address.m_state; // separates the address for output
    return output;
}

/*
 * Function: Overrides the == operator so we can check if two addresses are the same without calls to each of their individual components
 * Inputs: Address -- two Address classes, that are constant references, to be compared to see if they are the same
 * Output: bool -- returns if the given address are the same or not as a boolean
 */
bool operator==(const Address &a1, const Address &a2) {
    return (a1.m_city == a2.m_city) && (a1.m_state == a2.m_state); // separates the address for comparison
}
