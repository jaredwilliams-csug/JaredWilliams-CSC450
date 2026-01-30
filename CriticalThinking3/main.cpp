#include <iostream>
using namespace std;

int main() {

    int* ptr1 = new int;
    int* ptr2 = new int;
    int* ptr3 = new int;

    cout << "Please enter a number: ";
    cin >> *ptr1;

    cout << "Please enter a second number: ";
    cin >> *ptr2;

    cout << "Please enter a third number: ";
    cin >> *ptr3;

    cout << "The value: " << *ptr1 << " is stored at memory location " << &ptr1 << endl;
    cout << "The value: " << *ptr2 << " is stored at memory location " << &ptr2 << endl;
    cout << "The value: " << *ptr3 << " is stored at memory location " << &ptr3 << endl;

    delete ptr1;
    delete ptr2;
    delete ptr3;

    ptr1 = nullptr;
    ptr2 = nullptr;
    ptr3 = nullptr;

    return 0;
}