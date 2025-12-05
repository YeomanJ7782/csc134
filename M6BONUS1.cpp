/*
CSC 134
M6BONUS1
Julie Yeoman
12/5/2025
*/

#include <iostream>
#include <string>
using namespace std;

// function declarations
void part1();
void part2();

int main() {
    part1();
    part2();
    return 0;
}

// Part 1: Loop, NO arrays
void part1() {
    cout << "Part 1: No Arrays" << endl;

    int days;
    cout << "How many days do you want to enter? ";
    cin >> days;

    int total = 0;

    for (int i = 1; i <= days; i++) {
        int cars;
        cout << "Enter cars sold for day " << i << ": ";
        cin >> cars;
        total += cars;
    }

    cout << "Total cars sold: " << total << endl;
    cout << endl;
}

// Part 2: Arrays + Loop
void part2() {
    cout << "Part 2: Arrays" << endl;

    const int NUM_ROOMS = 5;

    // room names
    string roomNames[NUM_ROOMS] = {
        "Pastel Entryway",
        "Lavender Reading Room",
        "Peach Tea Kitchen",
        "Blooming Garden Terrace",
        "Dusty Rose Cellar"
    };

    // descriptions
    string roomDescriptions[NUM_ROOMS] = {
        "A quiet entryway with soft pink walls and a gentle fresh linen breeze.",
        "A cozy reading nook full of lavender cushions and a warm lamplight.",
        "A calming peach toned kitchen with a steaming teapot and rose plated dishes.",
        "A terrace decorated with soft blossoms, climbing vines, and warm daylight.",
        "A cool cellar with dusty rose bricks and ribbon tied boxes in the shadows."
    };

    // items in each room
    string roomItems[NUM_ROOMS] = {
        "hand painted keychain",
        "pressed flower bookmark",
        "peach patterned mug",
        "pastel watering can",
        "rose tinted lantern"
    };

    // Print all rooms using a loop
    for (int i = 0; i < NUM_ROOMS; i++) {
        cout << "Room " << i + 1 << ": " << roomNames[i] << endl;
        cout << "Description: " << roomDescriptions[i] << endl;
        cout << "Item found here: " << roomItems[i] << endl;
        cout << "-----------------------------" << endl;
    }

    cout << endl;
}
