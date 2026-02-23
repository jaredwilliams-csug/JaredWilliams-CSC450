#include <algorithm>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

std::string read(std::string fileName);
void appendToFile(std::string fileName, std::string content);
void write(std::string fileName, std::string content);
std::string reverseString(std::string str);

int main() {
    std::string input;
    std::string fileName = "CSC450_CT5_mod5.txt";
    std::string outputFileName = "CSC450-mod5-reverse.txt";

    read(fileName);
    std::cout << "Please enter text to append to this file" << std::endl;
    std::getline(std::cin, input);
    appendToFile(fileName, input);
    std::string text = read(fileName);

    write(outputFileName, reverseString(text));
    read(outputFileName);
    return 0;
}

std::string read(std::string fileName) {
    std::ifstream readFile(fileName);
    std::string text;
    std::string line;

    if (!readFile) {
        std::cerr << "Unable to find or open: " << fileName << std::endl;
        std::cout << "Looked in: " << std::filesystem::current_path() << std::endl;
        return "";
    }

    std::cout << "--- File Contents ---" << std::endl;
    while (std::getline(readFile, line)) {
        // Since I am using Linux, this handles the Windows carriage return
        // that is in the provided file.
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        text += line + "\n";
        std::cout << line << std::endl;
    }
    readFile.close();
    return text;
}

void appendToFile(std::string fileName, std::string content) {
    std::ofstream outFile(fileName, std::ios::app);

    if (outFile.is_open()) {
        outFile << content << std::endl;
        outFile.close();
        std::cout << "Successfully appended to " << fileName << std::endl;
    } else {
        std::cerr << "Error: Could not open file for appending." << std::endl;
    }
}

void write(std::string fileName, std::string content) {
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << content << std::endl;
    } else {
        std::cerr << "Error: Could not open file for writing." << std::endl;
    }
    outFile.close();
}

std::string reverseString(std::string str) {
    std::reverse(str.begin(), str.end());
    return str;
}