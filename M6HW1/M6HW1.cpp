/*
CSC 134
M6HW1 - Gold
Julie Yeoman
12/7/2025
*/

#include <iostream>
#include <string>
using namespace std;

// Direction constants (enum)
enum Direction { NORTH = 0, EAST, SOUTH, WEST, NUM_DIRECTIONS };
const string DIRECTION_NAMES[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

// Room constants (enum)
enum Room { ENTRYWAY = 0, LAVENDER_ROOM, PEACH_KITCHEN, BLOOM_GARDEN, ROSE_CELLAR, TREASURE_ROOM, NUM_ROOMS };

int main() {
    string roomNames[NUM_ROOMS] = {
        "Pastel Entryway",
        "Lavender Reading Room",
        "Peach Tea Kitchen",
        "Bloom Garden Terrace",
        "Dusty Rose Cellar",
        "Secret Treasure Room"
    };

    string roomDescriptions[NUM_ROOMS] = {
        "A soft pink foyer with warm sunlight and floral wallpaper.",
        "A lilac room full of pillows, books, and gentle light. A sign reads: 'Knowledge is the key!'",
        "A peach colored kitchen with a warm teapot on the stove.",
        "A garden terrace blooming in soft pastel flowers.",
        "A dusty rose cellar filled with boxes tied in ribbon.",
        "A hidden room glittering with gold and jewels! You've found the treasure!"
    };

    string roomItems[NUM_ROOMS] = {
        "a pastel keychain",
        "a lavender bookmark",
        "a cup of peach tea",
        "a soft pink flower",
        "a small rose quartz stone",
        "a golden key"
    };

    bool itemTaken[NUM_ROOMS] = { false, false, false, false, false, false };
    string inventory[10];
    int inventoryCount = 0;

    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    for (int r = 0; r < NUM_ROOMS; r++)
        for (int d = 0; d < NUM_DIRECTIONS; d++)
            connections[r][d] = -1;

    // Map layout
    connections[ENTRYWAY][NORTH] = LAVENDER_ROOM;
    connections[ENTRYWAY][EAST]  = PEACH_KITCHEN;
    connections[ENTRYWAY][WEST]  = BLOOM_GARDEN;

    connections[LAVENDER_ROOM][SOUTH] = ENTRYWAY;
    connections[LAVENDER_ROOM][EAST]  = TREASURE_ROOM; // Locked room

    connections[PEACH_KITCHEN][WEST]  = ENTRYWAY;
    connections[PEACH_KITCHEN][SOUTH] = ROSE_CELLAR;

    connections[BLOOM_GARDEN][EAST] = ENTRYWAY;

    connections[ROSE_CELLAR][NORTH] = PEACH_KITCHEN;

    int currentRoom = ENTRYWAY;
    bool running = true;

    while (running) {
        cout << "\nYou are in the " << roomNames[currentRoom] << ".\n";
        cout << roomDescriptions[currentRoom] << "\n";

        if (!itemTaken[currentRoom])
            cout << "You see " << roomItems[currentRoom] << " here.\n";

        cout << "Exits: ";
        bool printed = false;
        for (int d = 0; d < NUM_DIRECTIONS; d++)
            if (connections[currentRoom][d] != -1) {
                cout << DIRECTION_NAMES[d] << " ";
                printed = true;
            }
        if (!printed) cout << "none";
        cout << "\n";

        cout << "\nWhat would you like to do? ";
        string command;
        cin >> command;

        if (command == "n") command = "north";
        if (command == "e") command = "east";
        if (command == "s") command = "south";
        if (command == "w") command = "west";

        // Handle movement
        bool moved = false;
        for (int d = 0; d < NUM_DIRECTIONS; d++) {
            if (command == DIRECTION_NAMES[d]) {
                int nextRoom = connections[currentRoom][d];

                // Lock-and-key: Treasure Room requires golden key
                if (nextRoom == TREASURE_ROOM) {
                    bool hasKey = false;
                    for (int i = 0; i < inventoryCount; i++)
                        if (inventory[i] == "a pastel keychain") hasKey = true;

                    if (!hasKey) {
                        cout << "The door to the Treasure Room is locked! You need a key.\n";
                        moved = true;
                        break;
                    } else {
                        cout << "You use the pastel keychain to unlock the door!\n";
                    }
                }

                if (nextRoom != -1) currentRoom = nextRoom;
                else cout << "You can't go that way.\n";

                moved = true;
                break;
            }
        }
        if (moved) {
            // Gold tier ending
            if (currentRoom == TREASURE_ROOM) {
                cout << "\nCongratulations! You've found the treasure and completed the game!\n";
                running = false;
            }
            continue;
        }

        // Take item
        if (command == "take") {
            if (!itemTaken[currentRoom]) {
                cout << "You pick up " << roomItems[currentRoom] << ".\n";
                inventory[inventoryCount++] = roomItems[currentRoom];
                itemTaken[currentRoom] = true;
            } else cout << "There is nothing to take.\n";
            continue;
        }

        // Show inventory
        if (command == "inventory") {
            cout << "\nYou are carrying:\n";
            if (inventoryCount == 0) cout << "Nothing yet.\n";
            else for (int i = 0; i < inventoryCount; i++) cout << "- " << inventory[i] << "\n";
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
