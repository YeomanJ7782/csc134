/*
CSC 134
M6HW1 - Gold
Julie Yeoman
12/7/2025
*/

#include <iostream>
using namespace std;

int main() {
    bool has_key = false;
    string choice;

    cout << "Welcome to the Gold-Tier Adventure Game!" << endl;
    cout << "----------------------------------------" << endl;

    // Room 1
    cout << "You wake up in a dark forest. You see two paths. Do you go 'left' or 'right'? ";
    cin >> choice;

    if (choice == "left") {
        // Room 2: Cabin
        cout << "You follow the path and find a small cabin. There's an old chest here." << endl;
        cout << "Do you 'open' the chest or 'leave' it? ";
        cin >> choice;

        if (choice == "open") {
            cout << "The chest is locked. You need a key. You see a note on the table." << endl;
            cout << "Do you 'read' the note or 'ignore' it? ";
            cin >> choice;

            if (choice == "read") {
                cout << "The note says: 'The key is under the rock outside.' You go outside and find a key!" << endl;
                has_key = true;
            } else {
                cout << "You ignore the note. The chest remains locked. Game over." << endl;
                return 0;
            }
        }

        // After getting the key
        cout << "Do you 'open' the chest now or 'leave' it? ";
        cin >> choice;

        if (choice == "open" && has_key) {
            cout << "You use the key to unlock the chest. Inside, you find a treasure! You win!" << endl;
        } else {
            cout << "You decide to leave the chest. Maybe next time. Game over." << endl;
        }

    } else if (choice == "right") {
        // Room 2: Bear Encounter
        cout << "You walk along the path and encounter a bear. Do you 'run' or 'climb' a tree? ";
        cin >> choice;

        if (choice == "run") {
            cout << "The bear catches you. Game over!" << endl;
        } else if (choice == "climb") {
            cout << "You safely escape the bear. You see a sparkling key on a branch above. Do you 'take' it or 'ignore' it? ";
            cin >> choice;

            if (choice == "take") {
                has_key = true;
                cout << "You take the key and see a hidden treasure chest nearby. Do you 'open' it or 'leave' it? ";
                cin >> choice;

                if (choice == "open" && has_key) {
                    cout << "You unlock the chest with your key and discover gold! You win!" << endl;
                } else {
                    cout << "You ignore the chest. Game over." << endl;
                }

            } else {
                cout << "You ignore the key. Without it, you cannot access the treasure. Game over." << endl;
            }
        } else {
            cout << "You freeze in fear. The bear notices you. Game over!" << endl;
        }

    } else {
        cout << "You wander aimlessly until night falls. Game over." << endl;
    }

    cout << "\nThanks for playing the Gold-Tier Adventure Game!" << endl;
    return 0;
}
