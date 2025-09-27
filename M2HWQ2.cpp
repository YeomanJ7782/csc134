/*
CSC 134
M2HW Question 2
Julie Yeoman
September 26 2025
*/

#include <iomanip>
using namespace std;

int main() {
    // Constants for cost and amount charged
    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;

    // Variables
    double length, // for the crate's length
            width, // for the crate's width
            height, // for the crate's height
            volume, // for the volume of the crate
            cost,   // for the cost to build the crate
            charge, // amount to charge customer for the crate
            profit; // amount made on the crate

        // Set desired output formatting for numbers
        cout << setprecision(2) << fixed << showpoint;

        // Prompt the user for the crate's length, width and height
        cout << "Question 2" << endl;
        cout << "Enter the dimensions of the crate (in feet):\n";
        cout << "Length: "; 
        cin >> length;
        cout << "Width: ";
        cin >> width;
        cout << "Height: ";
        cin >> height;

        // Calculate volume of the create and cost to produce it
        // the amount to charge customer and the profit
        volume = length * width * height;
        cost = volume * COST_PER_CUBIC_FOOT;
        charge = volume * CHARGE_PER_CUBIC_FOOT;
        profit = charge - cost;

        // Display results
        cout << "The volume of the crate is: ";
        cout << volume << " cubic feet.\n";
        cout << "Cost to build: $" << cost << endl;
        cout << "Charge to customer: $" << charge << endl;
        cout << "Profit: $" << profit << endl;

        return 0; // no errors
}