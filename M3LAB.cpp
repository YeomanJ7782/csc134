/*
CSC 134
M3LAB1 - example 2
Julie Yeoman
9/30/2025
*/


#include <iostream>
#include <string>
using namespace std;

int main() {
    // declare variable
    string choice;

    // ask the user a question
    cout << "You encounter a mysterious cave with three tunnels." << endl;
    cout << "Do you choose Tunnel 1, Tunnel 2, or Tunnel 3?" << endl;
    cout << "Type 1, 2, or 3: ";
    cin >> choice;

    // make decision based on choice
    if (choice == "1") {
        cout << "You chose Tunnel 1. A treasure chest is waiting for you!" << endl;
    }
    else if (choice == "2") {
        cout << "You chose Tunnel 2. A dragon blocks your path!" << endl;
    }
    else if (choice == "3") {
        cout << "You chose Tunnel 3. You find a hidden escape route to safety." << endl;
    }
    else {
        cout << "I'm sorry, '" << choice << "' is not a valid choice." << endl;
    }

    // finish up
    cout << "Thanks for playing!" << endl;

    return 0; // no errors
}
