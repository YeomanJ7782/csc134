/*
CSC 134
M6HW1 - Gold
Julie Yeoman
12/7/2025
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Direction constants (enum)
enum Direction { NORTH = 0, EAST, SOUTH, WEST, NUM_DIRECTIONS };
const string DIRECTION_NAMES[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

// Room constants (enum)
enum Room { ENTRYWAY = 0, LAVENDER_ROOM, PEACH_KITCHEN, BLOOM_GARDEN, ROSE_CELLAR, TREASURE_ROOM, NUM_ROOMS };

// Helper function to make string lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

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
        ""
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

    // Clear game instructions
    cout << "Welcome to the Pastel Cottage Adventure!\n";
    cout << "Your goal is to find the hidden treasure in the cottage.\n";
    cout << "To win, you must explore the rooms, collect important items, and unlock the Treasure Room.\n";
    cout << "Type 'help' at any time to see available commands.\n";

    while (running) {
        cout << "\n--- " << roomNames[currentRoom] << " ---\n";
        cout << roomDescriptions[currentRoom] << "\n";

        if (!itemTaken[currentRoom] && roomItems[currentRoom] != "")
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

        // Special reminder for key rooms
        if (currentRoom == LAVENDER_ROOM && !itemTaken[ENTRYWAY])
            cout << "Remember: you may need items from other rooms to unlock new doors!\n";

        cout << "\nWhat would you like to do? ";
        string command;
        getline(cin, command);
        command = toLower(command);

        if (command == "n") command = "north";
        if (command == "e") command = "east";
        if (command == "s") command = "south";
        if (command == "w") command = "west";

        if (command == "help") {
            cout << "\nAvailable commands:\n";
            cout << "- north, south, east, west (or n, s, e, w) to move\n";
            cout << "- take (to pick up an item in the room)\n";
            cout << "- inventory (to check your items)\n";
            cout << "- quit (to exit the game)\n";
            continue;
        }

        // Handle movement
        bool moved = false;
        for (int d = 0; d < NUM_DIRECTIONS; d++) {
            if (command == DIRECTION_NAMES[d]) {
                int nextRoom = connections[currentRoom][d];

                if (nextRoom == TREASURE_ROOM) {
                    bool hasKey = false;
                    for (int i = 0; i < inventoryCount; i++)
                        if (inventory[i] == "a pastel keychain") hasKey = true;

                    if (!hasKey) {
                        cout << "The door to the Treasure Room is locked! You need a pastel keychain to enter.\n";
                        moved = true;
                        break;
                    } else {
                        cout << "You use the pastel keychain to unlock the door!\n";
                    }
                }

                if (nextRoom != -1) currentRoom = nextRoom;
                else cout << "You can't go that way.\n";

                moved = true;

                if (currentRoom == TREASURE_ROOM) {
                    cout << "\n🎉 Congratulations! You've found the treasure and won the game! 🎉\n";
                    running = false;
                }
                break;
            }
        }
        if (moved) continue;

        if (command == "take") {
            if (!itemTaken[currentRoom] && roomItems[currentRoom] != "") {
                cout << "You pick up " << roomItems[currentRoom] << ".\n";
                inventory[inventoryCount++] = roomItems[currentRoom];
                itemTaken[currentRoom] = true;

                cout << "Your inventory now contains:\n";
                for (int i = 0; i < inventoryCount; i++) cout << "- " << inventory[i] << "\n";
            } else {
                cout << "There is nothing to take here.\n";
            }
            continue;
        }

        if (command == "inventory") {
            cout << "\nYou are carrying:\n";
            if (inventoryCount == 0) cout << "Nothing yet.\n";
            else for (int i = 0; i < inventoryCount; i++) cout << "- " << inventory[i] << "\n";
            continue;
        }

        if (command == "quit") {
            cout << "Thanks for playing! Goodbye.\n";
            running = false;
            continue;
        }

        cout << "I don't understand that command. Type 'help' for a list of commands.\n";
    }

    return 0;
}

