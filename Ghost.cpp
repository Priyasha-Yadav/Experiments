// 💾 4. Ghost in the File System
// A ghost 👻 haunts your computer and keeps writing "BOO!\n" into your text file every night.
// Write a program that opens a file, appends the ghost’s message, and displays the full content. Bonus: reverse the text if it’s haunted.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("data.txt"); // Create and open file
    if (outFile.is_open()) {
        outFile << "Hello, this is a test file!" << endl;
        outFile << "File handling in C++ is very useful.";
        outFile.close();
        cout << "Data written successfully." << endl;
    } else {
        cout << "Error opening file." << endl;
    }
    return 0;
}