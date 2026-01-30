#include <iostream>
using namespace std;

string concat(const string& firstName, const string& lastName);
void welcome();

int main() {
    welcome();
    welcome();
    welcome();
    return 0;
}

void welcome() {
    string firstName, lastName;
    cout << "Enter your first name:";
    cin >> firstName;
    cout << "Enter your last name:";
    cin >> lastName;
    cout << "Welcome " << concat(firstName, lastName) << endl;
}

string concat(const string& firstName, const string& lastName) {
    return firstName + " " + lastName;
}
