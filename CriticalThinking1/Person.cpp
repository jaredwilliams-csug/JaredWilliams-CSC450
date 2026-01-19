#include "Person.h"
#include <ostream>
#include <iostream>
// Getters

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getLastName() const {
    return lastName;
}

std::string Person::getStreetAddress() const {
    return streetAddress;
}

std::string Person::getCity() const {
    return city;
}

std::string Person::getZipCode() const {
    return zipCode;
}

// Setters

void Person::setFirstName(std::string fName) {
    firstName = fName;
}

void Person::setLastName(std::string lName) {
    lastName = lName;
}

void Person::setStreetAddress(std::string stAddress) {
    streetAddress = stAddress;
}

void Person::setCity(std::string cty) {
    city = cty;
}

void Person::setZipCode(std::string zip) {
    zipCode = zip;
}

void Person::printName() const {
    std::cout << firstName << std::endl;
    std::cout << lastName << std::endl;
    std::cout << streetAddress << std::endl;
    std::cout << city << std::endl;
    std::cout << zipCode << std::endl;
}

