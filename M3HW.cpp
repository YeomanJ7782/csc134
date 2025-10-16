// CSC 134
// M3HW1 - Gold
// Your Name
// Date
// This program completes all four M3HW1 questions using if statements.
// Each question is separated and labeled for clarity.

#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

int main() {

    // -------------------------------
    // Question 1: Simple Chat Bot
    // -------------------------------
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


    // -------------------------------
    // Question 2: Receipt Calculator
    // -------------------------------
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
    cout << "----------
