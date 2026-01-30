#include <iostream>
using namespace std;

void printPtr(std::string *text);
void printVal(std::string text);
void printExample();
void arrayExample();

int main() {
    printExample();
    arrayExample();
    return 0;
}

void arrayExample() {
    int size;
    cout << "Please enter the size of the array: " << endl;
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = i*2;
    }
    for (int i = 0; i < size; i++) {
        cout << *(array+i) << " ";
    }
    delete [] array;
    array = nullptr;
}

void printPtr(std::string *text) {
    cout << *text << endl;
    cout << "at memory location from Pointer: " << &text << endl;
}

void printVal(std::string text) {
    cout << text << endl;
    cout << "at memory location from Value: " << &text << endl;
}
void printExample() {
    string output = "¡Hello World!";
    string* text = &output;

    printPtr(text);
    printPtr(text);
    printPtr(text);

    printVal(output);
    printVal(output);
    printVal(output);
}