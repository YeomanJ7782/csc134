/*
CSC 134
M2T2
Julie Yeoman
9/25/2025
*/

#include <iostream>
#include <iomanip> // for 2 decimal places
using namespace std;

int main() {
    // creating a simple receipt
    // should handle sales tax 8%

    // Declare variables
    string item = "Burger";
    double item_price = 5.99;
    double tax_percent = 0.08;   // 8 percent is 8/100
    double tax_amount;           // tax in dollars     
    double total;                // price + tax

    // Greet user and take order
    cout << "Welcome to our CSC 134 Restaurant!" << endl;
    cout << "You ordered one " << item << "." << endl;


    // Calculate the meal price
    tax_amount = item_price + tax_percent; // take 8% of the item
    total = item_price + tax_amount;


    // Print the reciept 
    cout << setprecision(2) << fixed;
    cout << total << endl;


    return 0; // no errors
}