/* C
CSC 134
M5HW1 - Gold
Julie Yeoman
11/
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void q1_averageRainfall();
void q2_blockVolume();
void q3_romanNumeral();
void q4_geometryCalculator();
void q5_distanceTraveled();
void mainMenu();

// --- MAIN ---
int main() {
    int choice = 0;
    do {
        cout << "\n=========================\n";
        cout << "      MAIN MENU\n";
        cout << "=========================\n";
        cout << "1. Average Rainfall\n";
        cout << "2. Block Volume\n";
        cout << "3. Roman Numeral Converter\n";
        cout << "4. Geometry Calculator\n";
        cout << "5. Distance Traveled\n";
        cout << "6. Quit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: q1_averageRainfall(); break;
            case 2: q2_blockVolume(); break;
            case 3: q3_romanNumeral(); break;
            case 4: q4_geometryCalculator(); break;
            case 5: q5_distanceTraveled(); break;
            case 6: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice. Please select 1–6.\n"; break;
        }
    } while (choice != 6);

    return 0;
}

// ------------------------------------------------------------
// QUESTION 1 – Average Rainfall
// ------------------------------------------------------------
void q1_averageRainfall() {
    string month1, month2, month3;
    double rain1, rain2, rain3;

    cout << "\nEnter month: ";
    cin >> month1;
    cout << "Enter rainfall for " << month1 << ": ";
    cin >> rain1;

    cout << "Enter month: ";
    cin >> month2;
    cout << "Enter rainfall for " << month2 << ": ";
    cin >> rain2;

    cout << "Enter month: ";
    cin >> month3;
    cout << "Enter rainfall for " << month3 << ": ";
    cin >> rain3;

    double average = (rain1 + rain2 + rain3) / 3.0;
    cout << fixed << setprecision(2);
    cout << "The average rainfall for " << month1 << ", " << month2
         << ", and " << month3 << " is " << average << " inches.\n";
}

// ------------------------------------------------------------
// QUESTION 2 – Volume of a Block
// ------------------------------------------------------------
void q2_blockVolume() {
    double length, width, height;

    cout << "\nEnter the block's length: ";
    cin >> length;
    cout << "Enter the block's width: ";
    cin >> width;
    cout << "Enter the block's height: ";
    cin >> height;

    if (length <= 0 || width <= 0 || height <= 0) {
        cout << "Error: All sides must be greater than zero.\n";
        return;
    }

    double volume = length * width * height;
    cout << fixed << setprecision(2);
    cout << "The volume of the block is " << volume << " cubic units.\n";
}

// ------------------------------------------------------------
// QUESTION 3 – Roman Numeral Converter
// ------------------------------------------------------------
void q3_romanNumeral() {
    int number;
    cout << "\nEnter a number (1–10): ";
    cin >> number;

    if (number < 1 || number > 10) {
        cout << "Error: number must be between 1 and 10.\n";
        return;
    }

    string roman;
    switch (number) {
        case 1: roman = "I"; break;
        case 2: roman = "II"; break;
        case 3: roman = "III"; break;
        case 4: roman = "IV"; break;
        case 5: roman = "V"; break;
        case 6: roman = "VI"; break;
        case 7: roman = "VII"; break;
        case 8: roman = "VIII"; break;
        case 9: roman = "IX"; break;
        case 10: roman = "X"; break;
    }
    cout << "The Roman numeral version of " << number << " is " << roman << ".\n";
}

// ------------------------------------------------------------
// QUESTION 4 – Geometry Calculator
// ------------------------------------------------------------
void q4_geometryCalculator() {
    int choice;
    const double PI = 3.14159;

    cout << "\nGeometry Calculator\n";
    cout << "1. Calculate the Area of a Circle\n";
    cout << "2. Calculate the Area of a Rectangle\n";
    cout << "3. Calculate the Area of a Triangle\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1–4): ";
    cin >> choice;

    cout << fixed << setprecision(2);

    if (choice == 1) {
        double radius;
        cout << "Enter the circle's radius: ";
        cin >> radius;
        if (radius < 0) {
            cout << "The radius cannot be less than zero.\n";
            return;
        }
        cout << "The area is " << PI * radius * radius << endl;
    } else if (choice == 2) {
        double length, width;
        cout << "Enter the rectangle's length: ";
        cin >> length;
        cout << "Enter the rectangle's width: ";
        cin >> width;
        if (length < 0 || width < 0) {
            cout << "Length and width must be positive.\n";
            return;
        }
        cout << "The area is " << length * width << endl;
    } else if (choice == 3) {
        double base, height;
        cout << "Enter the triangle's base: ";
        cin >> base;
        cout << "Enter the triangle's height: ";
        cin >> height;
        if (base < 0 || height < 0) {
            cout << "Only enter positive values for base and height.\n";
            return;
        }
        cout << "The area is " << 0.5 * base * height << endl;
    } else if (choice == 4) {
        cout << "Returning to main menu...\n";
        return;
    } else {
        cout << "The valid choices are 1 through 4.\n";
    }
}

// ------------------------------------------------------------
// QUESTION 5 – Distance Traveled
// ------------------------------------------------------------
void q5_distanceTraveled() {
    double speed;
    int hours;

    cout << "\nWhat is the speed of the vehicle in mph? ";
    cin >> speed;
    cout << "How many hours has it traveled? ";
    cin >> hours;

    if (speed < 0 || hours < 1) {
        cout << "Error: Speed must be non-negative and hours must be at least 1.\n";
        return;
    }

    cout << "\nHour\tDistance Traveled\n";
    cout << "---------------------------\n";
    for (int i = 1; i <= hours; i++) {
        cout << setw(4) << i << "\t" << setw(8) << (speed * i) << endl;
    }
}
