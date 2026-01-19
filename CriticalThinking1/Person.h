#ifndef CRITICALTHINKING1_PERSON_H
#define CRITICALTHINKING1_PERSON_H
#include <string>

class Person {
    std::string firstName;
    std::string lastName;
    std::string streetAddress;
    std::string city;
    std::string zipCode;

public:

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getStreetAddress() const;
    std::string getCity() const;
    std::string getZipCode() const;

    void setFirstName(std::string fName);
    void setLastName(std::string lName);
    void setStreetAddress(std::string stAddress);
    void setCity(std::string cty);
    void setZipCode(std::string zip);
    void printName() const;

};
#endif //CRITICALTHINKING1_PERSON_H