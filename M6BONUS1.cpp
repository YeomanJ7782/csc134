/*
CSC 134
M6BONUS1
Julie Yeoman
12/5/2025
*/

#include <iostream>
#include <string>
using namespace std;

// Direction constants (enum)
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Room constants (enum)
enum Room {
    ENTRYWAY = 0,
    LAVENDER_ROOM = 1,
    PEACH_KITCHEN = 2,
    BLOOM_GARDEN = 3,
    ROSE_CELLAR = 4,
    NUM_ROOMS = 5
};

int main() {

    // PARALLEL ARRAYS

    string roomNames[NUM_ROOMS] = {
        "Pastel Entryway",
        "Lavender Reading Room",
        "Peach Tea Kitchen",
        "Bloom Garden Terrace",
        "Dusty Rose Cellar"
    };

    string roomDescriptions[NUM_ROOMS] = {
        "A soft pink foyer with warm sunlight and floral wallpaper.",
        "A lilac room full of pillows, books, and gentle light.",
        "A peach colored kitchen with a warm teapot on the stove.",
        "A garden terrace blooming in soft pastel flowers.",
        "A dusty rose cellar filled with boxes tied in ribbon."
    };

    // Each room has a single item
    string roomItems[NUM_ROOMS] = {
        "a pastel keychain",
        "a lavender bookmark",
        "a cup of peach tea",
        "a soft pink flower",
        "a small rose quartz stone"
    };

    // Track whether item has been taken
    bool itemTaken[NUM_ROOMS] = { false, false, false, false, false };

    // Player inventory (simple array)
    string inventory[10];
    int inventoryCount = 0;

    // ADJACENCY LIST (2D ARRAY)

    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Initialize all to -1
    for (int r = 0; r < NUM_ROOMS; r++) {
        for (int d = 0; d < NUM_DIRECTIONS; d++) {
            connections[r][d] = -1;
        }
    }

    // Map layout
    connections[ENTRYWAY][NORTH] = LAVENDER_ROOM;
    connections[ENTRYWAY][EAST]  = PEACH_KITCHEN;
    connections[ENTRYWAY][WEST]  = BLOOM_GARDEN;

    connections[LAVENDER_ROOM][SOUTH] = ENTRYWAY;

    connections[PEACH_KITCHEN][WEST]  = ENTRYWAY;
    connections[PEACH_KITCHEN][SOUTH] = ROSE_CELLAR;

    connections[BLOOM_GARDEN][EAST] = ENTRYWAY;

    connections[ROSE_CELLAR][NORTH] = PEACH_KITCHEN;

    // GAME STATE

    int currentRoom = ENTRYWAY;
    bool running = true;

    // GAME LOOP
    while (running) {

        cout << "\nYou are in the " << roomNames[currentRoom] << ".\n";
        cout << roomDescriptions[currentRoom] << "\n";

        // Show item if not picked up
        if (!itemTaken[currentRoom]) {
            cout << "You see " << roomItems[currentRoom] << " here.\n";
        }

        // Show exits
        cout << "Exits: ";
        bool printed = false;
        for (int d = 0; d < NUM_DIRECTIONS; d++) {
            if (connections[currentRoom][d] != -1) {
                cout << DIRECTION_NAMES[d] << " ";
                printed = true;
            }
        }
        if (!printed) cout << "none";
        cout << "\n";

        // Input command
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;

        // Movement shortcuts
        if (command == "n") command = "north";
        if (command == "e") command = "east";
        if (command == "s") command = "south";
        if (command == "w") command = "west";

        // Handle movement
        bool moved = false;
        for (int d = 0; d < NUM_DIRECTIONS; d++) {
            if (command == DIRECTION_NAMES[d]) {
                if (connections[currentRoom][d] != -1) {
                    currentRoom = connections[currentRoom][d];
                } else {
                    cout << "You can't go that way.\n";
                }
                moved = true;
                break;
            }
        }
        if (moved) continue;

        // Take item
        if (command == "take") {
            if (!itemTaken[currentRoom]) {
                cout << "You pick up " << roomItems[currentRoom] << ".\n";
                inventory[inventoryCount++] = roomItems[currentRoom];
                itemTaken[currentRoom] = true;
            } else {
                cout << "There is nothing to take.\n";
            }
            continue;
        }

        // Show inventory
        if (command == "inventory") {
            cout << "\nYou are carrying:\n";
            if (inventoryCount == 0) {
                cout << "Nothing yet.\n";
            } else {
                for (int i = 0; i < inventoryCount; i++) {
                    cout << "- " << inventory[i] << "\n";
                }
            }
            continue;
        }

        if (command == "quit") {
            running = false;
            continue;
        }

        cout << "I don't understand that command.\n";
    }

    cout << "\nThank you for exploring this pastel cottage!\n";
    return 0;
}
