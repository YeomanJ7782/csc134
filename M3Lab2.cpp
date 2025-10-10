/*
CSC 134
M3Lab2
Julie Yeoman
10/9/25
*/

#include <iostream>
using namespace std;

int main() {

    // declare variables
    int grade;
    char letterGrade;

    // Ask the user for input
    cout << "Enter your numerical grade: ";
    cin >> grade;

    // Input validation
    if (grade < 0 || grade > 100) {
        cout << "Invalid grade. Please enter a number between 0 and 100." << endl;
        return 1; // exit program with error code
    }

    // Determine letter grade
    if (grade >= 90 && grade <= 100) {
        letterGrade = 'A';
    } 
    else if (grade >= 80 && grade <= 89) {
        letterGrade = 'B';
    } 
    else if (grade >= 70 && grade <= 79) {
        letterGrade = 'C';
    } 
    else if (grade >= 60 && grade <= 69) {
        letterGrade = 'D';
    } 
    else { // grade between 0 and 59
        letterGrade = 'F';
    }

    // Display result
    cout << "Your letter grade is: " << letterGrade << endl;

    return 0;
}
