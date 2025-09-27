/*
CSC 134
M2HW Question 4
Julie Yeoman
September 26 2025
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables
    string letsGo, school, team;
    string cheerOne, cheerTwo;

    // Assign base values
    letsGo = "Let's go ";
    school = "FTCC";
    team = "Trojans";

    // Build cheers using concatenation
    cheerOne = letsGo + school;
    cheerTwo = letsGo + team;

    // Output the cheers
    cout << cheerOne << endl;
    cout << cheerOne << endl;
    cout << cheerOne << endl;
    cout << cheerTwo << endl;

    return 0;
}
