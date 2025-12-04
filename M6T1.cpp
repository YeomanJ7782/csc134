/*
CSC 134
M6T1
Julie Yeoman
12/3/2025
*/

#include <iostream>
using namespace std;

// function declarations
void method1();
void method2();

// main
int main() {
    // count number of cars per day, two different ways
    method1();
    method2();
    return 0;
}

// function definitions
void method1() {
    // method 1 - no arrays
    // count 5 days of cars, get total and average
    cout << "Part 1 - No arrays" << endl;
    cout << "Enter number of cars that passed each day" << endl;
    cout << "Day 0 = Monday, Day 4= Friday" << endl;

    const int DAYS = 5;
    int count = 0;
    int cars_today = 0; // current value, to add
    int cars_total = 0;      // add up
    double cars_avg = 0; // average

    while (count < DAYS) {
        cout << "Day " << count << ": ";
        cin >> cars_today;
        cars_total += cars_today;
        count++;
    }

    cars_avg = (double)cars_total / DAYS;

    cout << "Total Cars: " << cars_total << endl;
    cout << "Average per day: " << cars_avg << endl << endl;
}

// Part 2: Loop + Arrays
void method2() {
    // Method 2 uses 2 arrays
    // Names of the days
    // # of cars found on the days

    cout << "Part 2: Using Arrays" << endl;

    const int DAYS = 5;
    string days[DAYS] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
    int cars[DAYS];
    int cars_total = 0;
    double cars_avg = 0.0;

    // Input loop
    for (int i = 0; i < DAYS; i++) {
        cout << "# of cars on " << days[i] << ": ";
        cin >> cars[i];
    }


    // Print table
    cout << "Day\tCars" << endl;
    for (int i = 0; i < DAYS; i++) {
        cout << days[i] << "\t" << cars[i] << endl;
        cars_total += cars[i];
    }

    cars_avg = (double)cars_total / DAYS;

    cout << "Total Cars: " << cars_total << endl;
    cout << "Average per day: " << cars_avg << endl;

    // ASCII bar graph
    cout << "\nASCII Bar Graph:\n";
    for (int i = 0; i < DAYS; i++) {
        cout << days[i] << " | ";
        for (int j = 0; j < cars[i] / 5; j++) {  // scale bars / adjust as needed
            cout << "*";
        }
        cout << " (" << cars[i] << ")" << endl;
    }

    cout << endl;
}
