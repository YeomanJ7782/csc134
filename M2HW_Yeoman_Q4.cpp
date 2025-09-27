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
    string cheerOne, cheerTwo, cheerThree;

    // Assign base values
    letsGo = "Let's go ";
    school = "FTCC";
    team = "Trojans";

    // Build cheers using concatenation
    cheerOne = letsGo + team;
    cheerTwo = letsGo;
    cheerThree = letsGo + school;

    // Output the cheers
    cout << "Question 4" << endl;
    cout << cheerOne << endl;
    cout << cheerTwo << endl;
    cout << cheerOne << endl;
    cout << cheerTwo << endl;
    cout << cheerThree << endl;

    return 0;
}
