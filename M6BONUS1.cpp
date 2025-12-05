/*
CSC 134
M6BONUS1
Julie Yeoman
12/5/2025
*/

#include <iostream>
#include <string>
using namespace std;

// Direction constants
enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, NUM_DIRECTIONS = 4 };

const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Room constants
enum Room {
    ENTRYWAY = 0,
    LAVENDER_ROOM = 1,
    PEACH_KITCHEN = 2,
    BLOOM_GARDEN = 3,
    ROSE_CELLAR = 4,
    NUM_ROOMS = 5
};

int main() {

    // Room names
    string roomNames[NUM_ROOMS] = {
        "Pastel Entryway",
        "Lavender Reading Room",
        "Peach Tea Kitchen",
        "Blooming Garden Terrace",
        "Dusty Rose Cellar"
    };

    // Room descriptions
    string roomDescriptions[NUM_ROOMS] = {
        "A soft pink entryway with warm sunlight and floral wallpaper.",
        "A cozy lavender room full of pillows, books, and pastel lamps.",
        "A peach-colored kitchen with a steaming teapot and gentle glow.",
        "A bright garden terrace with blossoms in every soft color.",
        "A rose-hued cellar with ribbon-tied boxes and twinkling lights."
    };

    // Simple item system (1 item per room)
    string roomItems[NUM_ROOMS] = {
        "a pastel keychain",
        "a lavender bookmark",
        "a warm cup of peach tea",
        "a pink flower",
        "a tiny rose quartz stone"
    };

    // Track whether an item is still in its room
    bool itemTaken[NUM_ROOMS] = { false, false, false, false, false };

    // Player inventory (simple list)
    string inventory[10];
    int inventoryCount = 0;

    // Room connections
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    for (int r = 0; r < NUM_ROOMS; r++)
        for (int d = 0; d < NUM_DIRECTIONS; d++)
            connections[r][d] = -1;

    // Map layout
    connections[ENTRYWAY][NORTH] = LAVENDER_ROOM;
    connections[ENTRYWAY][EAST]  = PEACH_KITCHEN;
    connections[ENTRYWAY][WEST]  = BLOOM_GARDEN;

    connections[LAVENDER_ROOM][SOUTH] = ENTRYWAY;

    connections[PEACH_KITCHEN][WEST]  = ENTRYWAY;
    connections[PEACH_KITCHEN][SOUTH] = ROSE_CELLAR;

    connections[BLOOM_GARDEN][EAST] = ENTRYWAY;

    connections[ROSE_CELLAR][NORTH] = PEACH_KITCHEN;

    // Game state
    int currentRoom = ENTRYWAY;
    bool running = true;

    while (running) {

        // Room info
        cout << "\nYou are in the " << roomNames[currentRoom] << ".\n";
        cout << roomDescriptions[currentRoom] << "\n";

        // Show item if still available
        if (!itemTaken[currentRoom]) {
            cout << "You see " << roomItems[currentRoom] << " here.\n";
        }

        // Show exits
        cout << "Exits: ";
        bool foundExit = false;
        for (int d = 0; d < NUM_DIRECTIONS; d++) {
            if (connections[currentRoom][d] != -1) {
                cout << DIRECTION_NAMES[d] << " ";
                foundExit = true;
            }
        }
        if (!foundExit) cout << "none";
        cout << "\n";

        // Command input
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;

        // Normalize short commands
        if (command == "n") command = "north";
        if (command == "e") command = "east";
        if (command == "s") command = "south";
        if (command == "w") command = "west";

        // Movement handling
        bool moved = false;
        for (int d = 0; d < NUM_DIRECTIONS; d++) {
            if (command == DIRECTION_NAMES[d]) {
                if (connections[currentRoom][d] != -1) {
                    currentRoom = connections[currentRoom][d];
                } else {
                    cout << "You can't go that way!\n";
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
                cout << "There is nothing to take here.\n";
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

        // Quit game
        if (command == "quit") {
            running = false;
            continue;
        }

        // Unknown command
        cout << "I don't understand that command.\n";
    }

    cout << "\nThanks for exploring my pastel world!\n";

    return 0;
}

