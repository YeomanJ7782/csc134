/*
CSC 134
M4HW1 Gold
Julie Yeoman
10/28/25
*/

#include <iostream>
using namespace std;

int main() {
    int num;

    // Ask until valid input
    cout << "Enter a number from 1 to 12: ";
    cin >> num;

    while (num < 1 || num > 12) {
        cout << "Invalid input. Please enter a number between 1 and 12: ";
        cin >> num;
    }

    // Print times table
    int i = 1;
    while (i <= 12) {
        cout << num << " times " << i << " is " << num * i << "." << endl;
        i++;
    }

    return 0;
}
