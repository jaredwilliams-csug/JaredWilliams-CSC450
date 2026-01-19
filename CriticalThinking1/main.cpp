#include <iostream>
#include "Person.h"

int main() {
    Person person;
    person.setFirstName("John");
    person.setLastName("Smith");
    person.setStreetAddress("234 Main St");
    person.setCity("Broomfield");
    person.setZipCode("80021");
    person.printName();

    std::cout << "-------------" << std::endl;

    Person otherPerson;
    otherPerson.setFirstName("Frank");
    otherPerson.setLastName("Smith");
    otherPerson.setStreetAddress("24 Elm St");
    otherPerson.setCity("Jacksonville");
    otherPerson.setZipCode("32210");
    otherPerson.printName();
    return 0;
}