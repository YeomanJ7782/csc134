/*
CSC 134
M2HW Question 3
Julie Yeoman
September 26 2025
*/

#include <iostream>
using namespace std;

int main() {
    int pizzas, slicesPerPizza, visitors;
    int totalSlices, neededSlices, leftovers;

    // Input
    cout << "Question 3" << endl;
    cout << "Enter the number of pizzas ordered: ";
    cin >> pizzas;

    cout << "Enter the number of slices per pizza: ";
    cin >> slicesPerPizza;

    cout << "Enter the number of visitors: ";
    cin >> visitors;

    // Calculations
    totalSlices = pizzas * slicesPerPizza;
    neededSlices = visitors * 3;
    leftovers = totalSlices - neededSlices;

    // Output
    cout << "\n--- Pizza Party Report ---\n";
    cout << "Total slices available: " << totalSlices << endl;
    cout << "Total slices needed (3 per visitor): " << neededSlices << endl;
    cout << "Slices left over: " << leftovers << endl;

    return 0;
}
