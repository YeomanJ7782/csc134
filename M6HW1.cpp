/*
CSC 134
M6HW1 - Gold
Julie Yeoman
12/7/2025
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
    cout << "Do you like me? Please type yes or no: ";
    string answer;
    cin >> answer;

    if (answer == "yes") {
        cout << "That’s great! I’m sure we’ll get along." << endl;
    } else if (answer == "no") {
        cout << "Well, maybe you’ll learn to like me later." << endl;
    } else {
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

    // Question 3: Choose Your Own Adventure (Gold Version)
    cout << "Question 3: Choose Your Own Adventure - Gold Version" << endl;
    cout << "----------------------------------------------------" << endl;

    bool has_key = false;
    string choice;

    // Room 1
    cout << "You wake up in a dark forest. You see two paths. Do you go 'left' or 'right'? ";
    cin >> choice;

    if (choice == "left") {
        // Room 2
        cout << "You follow the path and find a small cabin. There's an old chest here." << endl;
        cout << "Do you 'open' the chest or 'leave' it? ";
        cin >> choice;

        if (choice == "open") {
            cout << "The chest is locked. You need a key. You see a note on the table." << endl;
            cout << "Do you 'read' the note or 'ignore' it? ";
            cin >> choice;

            if (choice == "read") {
                cout << "The note says: 'The key is under the rock outside.' You go outside and find a key!" << endl;
                has_key = true;
            } else {
                cout << "You ignore the note. The chest remains locked. Game over." << endl;
                return 0;
            }
        }

        // After getting the key
        cout << "Do you 'open' the chest now or 'leave' it? ";
        cin >> choice;

        if (choice == "open" && has_key) {
            cout << "You use the key to unlock the chest. Inside, you find a treasure! You win!" << endl;
        } else {
            cout << "You decide to leave the chest. Maybe next time. Game over." << endl;
        }

    } else if (choice == "right") {
        // Room 2 alternative
        cout << "You walk along the path and encounter a bear. Do you 'run' or 'climb' a tree? ";
        cin >> choice;

        if (choice == "run") {
            cout << "The bear catches you. Game over!" << endl;
        } else if (choice == "climb") {
            cout << "You safely escape the bear. You see a sparkling key on a branch above. Do you 'take' it or 'ignore' it? ";
            cin >> choice;

            if (choice == "take") {
                has_key = true;
                cout << "You take the key and see a hidden treasure chest nearby. Do you 'open' it or 'leave' it? ";
                cin >> choice;

                if (choice == "open" && has_key) {
                    cout << "You unlock the chest with your key and discover gold! You win!" << endl;
                } else {
                    cout << "You ignore the chest. Game over." << endl;
                }

            } else {
                cout << "You ignore the key. Without it, you cannot access the treasure. Game over." << endl;
            }
        } else {
            cout << "You freeze in fear. The bear notices you. Game over!" << endl;
        }

    } else {
        cout << "You wander aimlessly until night falls. Game over." << endl;
    }

    cout << "\n--------------------------------------------\n" << endl;

    // Question 4: Math Practice Program
    cout << "Question 4: Math Practice Program" << endl;
    cout << "--------------------------------" << endl;

    srand(time(0));  // Seed the random number generator

    int num1 = rand() % 10; // 0–9
    int num2 = rand() % 10; // 0–9

    cout << "What is " << num1 << " plus " << num2 << "? ";
    int user_answer;
    cin >> user_answer;

    int correct_answer = num1 + num2;

    if (user_answer == correct_answer) {
        cout << "Correct!" << endl;
    } else {
        cout << "Incorrect. The right answer was " << correct_answer << "." << endl;
    }

    cout << "\nThank you for completing M6HW1 - Gold Tier!" << endl;
    cout << "--------------------------------------------" << endl;

    return 0;
}

