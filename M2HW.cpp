/*
CSC 134
M2HW - Gold
Julie Yeoman
September 26 2025
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    // Question 1: Create a program simulating a banking transaction
    string firstName, lastName;
    double startingBalance, deposit, withdrawal, finalBalance;
    int accountNumber = rand();

    // Ask for user's name
    cout << "Question 1" << endl;
    cout << "Enter your first name: " << endl;
    cin >> firstName;
    cout << "Enter your last name: " << endl;
    cin >> lastName;

    // Ask for user's account details
    cout << "Enter your account balance: $" << endl;
    cin >> startingBalance;
    cout << "Enter deposit amount: $" << endl;
    cin >> deposit;
    cout << "Enter withdrawal amount: $" << endl;
    cin >> withdrawal;

    // Calculate the final balance
    finalBalance = startingBalance + deposit - withdrawal;

    // Display results 
    cout << fixed << setprecision(2);
    cout << "Account Summary" << endl;
    cout << "-----------------" << endl;
    cout << "Name on account: " << firstName << " " << lastName << endl;
    cout << "Account number: " << accountNumber << endl;
    cout << "Final balance: $" << finalBalance << endl;



return 0; // no errors

}