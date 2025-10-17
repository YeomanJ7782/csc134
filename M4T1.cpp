/*
CSC 134
M4T1
Julie Yeoman
10/16/2025
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // --- Program 5-3: Simple while loop to say Hello 5 times ---
    int count = 1;  // Counter variable

    cout << "Program 5-3: Saying Hello 5 times\n";
    while (count <= 5) {
        cout << "Hello\n";
        count++;
    }

    cout << endl; // Blank line for spacing

    // --- Program 5-6: Display a table of numbers and their squares ---
    int number = 1;  // Loop control variable

    cout << "Program 5-6: Numbers and their squares\n";
    cout << "Number\tSquare\n";
    cout << "-----------------\n";

    while (number <= 10) {
        cout << number << "\t" << (number * number) << endl;
        number++;
    }

    cout << "\nProgram complete.\n";

    return 0;
}
