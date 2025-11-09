/*
CSC 134
M5LAB1 - Choose Your Own Adventure
Julie Yeoman
11/8/2025
This program uses multiple void functions to create a simple interactive story.
*/


#include <iostream>
using namespace std;


// Function Prototypes
void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void choice_secret_tunnel(); // new branch!
void choice_garden();        // another new branch!

int main() {
    cout << "M5LAB1 - Choose Your Own Adventure" << endl;
    main_menu();
    cout << "Thanks for playing!" << endl;
    return 0;
}

void main_menu() {
    int choice;

    cout << "\nMain Menu" << endl;
    cout << "You're standing in front of a spooky old house..." << endl;
    cout << "Do you:" << endl;
    cout << "1. Try the front door" << endl;
    cout << "2. Sneak around back" << endl;
    cout << "3. Forget it, and go home" << endl;
    cout << "4. [Quit]" << endl;

    cout << "Choose: ";
    cin >> choice;

    if (choice == 1) {
        choice_front_door();
    } else if (choice == 2) {
        choice_back_door();
    } else if (choice == 3) {
        choice_go_home();
    } else if (choice == 4) {
        cout << "Ok, quitting game." << endl;
        return;
    } else {
        cout << "That's not a valid choice. Please try again." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        main_menu(); // restart menu
    }
}

// --- STORY FUNCTIONS ---

void choice_front_door() {
    cout << "\nYou walk up the creaky steps to the front door." << endl;
    cout << "You try the handle... it's locked!" << endl;
    cout << "Do you:" << endl;
    cout << "1. Check around back" << endl;
    cout << "2. Give up and go home" << endl;

    int choice;
    cout << "Choose: ";
    cin >> choice;

    if (choice == 1) {
        choice_back_door();
    } else if (choice == 2) {
        choice_go_home();
    } else {
        cout << "Invalid choice. Try again." << endl;
        choice_front_door();
    }
}

void choice_back_door() {
    cout << "\nYou sneak around the back of the house." << endl;
    cout << "You find a half-open door leading to a dark basement!" << endl;
    cout << "Do you:" << endl;
    cout << "1. Go inside the dark basement" << endl;
    cout << "2. Explore the garden instead" << endl;

    int choice;
    cout << "Choose: ";
    cin >> choice;

    if (choice == 1) {
        choice_secret_tunnel();
    } else if (choice == 2) {
        choice_garden();
    } else {
        cout << "Invalid choice. Try again." << endl;
        choice_back_door();
    }
}

void choice_go_home() {
    cout << "\nYou decide it's not worth the risk and go home." << endl;
    cout << "You make some hot cocoa and watch a movie. The end!" << endl;
}

void choice_secret_tunnel() {
    cout << "\nYou step into the dark basement and find a hidden tunnel!" << endl;
    cout << "You follow it and discover a chest full of gold coins!" << endl;
    cout << "Congratulations — you found the treasure!" << endl;
}

void choice_garden() {
    cout << "\nYou wander into the overgrown garden." << endl;
    cout << "Among the weeds, you find a shiny key!" << endl;
    cout << "Maybe it opens the front door...?" << endl;
    cout << "You hurry back to the main entrance!" << endl;
    choice_front_door();
}
