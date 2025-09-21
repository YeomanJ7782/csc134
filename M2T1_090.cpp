// CSC 134
// M2T1 - Product Sales
// Julie Yeoman
// 9/21/2025
// Making a simple "checkout" machine

#include <iostream>
#include <iomanip> // for the 2 decimal places
using namespace std;

int main()
{

    // Set up variables
    string first_name, last_name, full_name; // holds customer name
    string product = "cake"; // changed to cake
    double cost_each = 9.99;
    double total_cost;
    int amount_purchased;

    // Greet the customer
    cout << "Welcome to our " << product << " store!" << endl;
    cout << "What is your first name? ";
    cin >> first_name;
    cout << "What is your last name? ";
    cin >> last_name;
    full_name = first_name + " " + last_name;
    cout << "Nice to meet you, " << full_name << endl;

    
    // Ash how much they want to purchase
    cout << "How many " << product << " would you like today? ";
    cin >> amount_purchased;

    // Calculate total price
    total_cost = amount_purchased * cost_each;

    // Formatting: Set all prices to 2 decimal places
    cout << setprecision(2) << fixed;

    // Give result
    cout << "For " << amount_purchased << " " << product << endl;
    cout << "That will be: $" << total_cost << endl;
    cout << "Thank you for shopping with us!" << endl;

    
    return 0; // no errors
}