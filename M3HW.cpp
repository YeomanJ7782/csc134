/*
CSC 134
M3HW - Gold
Julie Yeoman
10/15/2025
*/



#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

int main() {

    // Question 1: Simple Chat Bot

    cout << "Question 1: Simple Chat Bot" << endl;
    cout << "---------------------------" << endl;

    cout << "Hello, I’m a C++ program!" << endl;
    cout << "Do you like me? Please type yes or no." << endl;

    string answer;
    cin >> answer;

    if (answer == "yes") {
        cout << "That’s great! I’m sure we’ll get along." << endl;
    }
    else if (answer == "no") {
        cout << "Well, maybe you’ll learn to like me later." << endl;
    }
    else {
        cout << "If you’re not sure… that’s OK." << endl;
    }

    cout << "\n--------------------------------------------\n" << endl;


    // Question 2: Receipt Calculator
    
    cout << "Question 2: Receipt Calculator" << endl;
    cout << "-------------------------------" << endl;

    double meal_price, tax, tip = 0, total;
    const double TAX_RATE = 0.07; // 7% sales tax

    cout << "Enter the price of your meal: $";
    cin >> meal_price;

    cout << "Please enter 1 if the order is dine in, 2 if it is to go: ";
    int order_type;
    cin >> order_type;

    tax = meal_price * TAX_RATE;

    if (order_type == 1) { // dine in
        tip = meal_price * 0.15;
    }

    total = meal_price + tax + tip;

    cout << "\n---- Receipt ----" << endl;
    cout << "Meal price: $" << meal_price << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Tip: $" << tip << endl;
    cout << "-----------------" << endl;
    cout << "Total due: $" << total << endl;

    cout << "\n--------------------------------------------\n" << endl;


    // Question 3: Choose Your Own Adventure

    cout << "Question 3: Choose Your Own Adventure" << endl;
    cout << "-------------------------------------" << endl;

    cout << "You wake up in a dark forest. Do you go 'left' or 'right'?" << endl;
    string choice1;
    cin >> choice1;

    if (choice1 == "left") {
        cout << "You find a river. Do you 'swim' across or 'follow' it?" << endl;
        string choice2;
        cin >> choice2;

        if (choice2 == "swim") {
            cout << "You are swept away by the current. Game over!" << endl;
        } 
        else if (choice2 == "follow") {
            cout << "You find a village and are saved. You win!" << endl;
        } 
        else {
            cout << "You hesitate too long and night falls. Game over." << endl;
        }
    } 
    else if (choice1 == "right") {
        cout << "You meet a bear. Do you 'run' or 'climb' a tree?" << endl;
        string choice2;
        cin >> choice2;

        if (choice2 == "run") {
            cout << "The bear catches you. Game over!" << endl;
        } 
        else if (choice2 == "climb") {
            cout << "You escape and live to tell the tale. You win!" << endl;
        } 
        else {
            cout << "You freeze in fear. Game over!" << endl;
        }
    } 
    else {
        cout << "You wander aimlessly until you get lost. Game over." << endl;
    }

    cout << "\n--------------------------------------------\n" << endl;


    // Question 4: Math Practice Program

    cout << "Question 4: Math Practice Program" << endl;
    cout << "--------------------------------" << endl;

    srand(time(0));  // Seed the random number generator

    int num1 = rand() % 10; // 0–9
    int num2 = rand() % 10; // 0–9

    cout << "What is " << num1 << " plus " << num2 << "?" << endl;
    int user_answer;
    cin >> user_answer;

    int correct_answer = num1 + num2;

    if (user_answer == correct_answer) {
        cout << "Correct!" << endl;
    } 
    else {
        cout << "Incorrect. The right answer was " << correct_answer << "." << endl;
    }

    cout << "\nThank you for completing M3HW1 - Gold Tier!" << endl;
    cout << "--------------------------------------------" << endl;

    return 0;
}
