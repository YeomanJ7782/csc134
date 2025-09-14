// csc 134
// M1LAB
// Julie Yeoman
// September 14, 2025

#include <iostream>
using namespace std;

int main() {
    string salesPersonName = "Jane Smith";
    int apples = 100;
    double pricePerApple = 0.25;

    cout << "Welcome to " << salesPersonName;
    cout << "'s apple farm" << endl;

    cout << "We have " << apples << " apples for sale" << endl;

    cout << "Price is $" << pricePerApple << " each." << endl;

    // calculate total price
    double totalPrice = (double) apples * pricePerApple;
    cout << "Total price is: $" <<totalPrice <<endl;
}