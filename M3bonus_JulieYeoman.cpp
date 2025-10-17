/*
CSC 134
M3 bonus
Julie Yeoman
10/16/2025
*/

#include <iostream>
#include <cstdlib>  // for rand(), srand()
#include <ctime>    // for time()

using namespace std;

int rollDice() {
    int die1 = rand() % 6 + 1;  // random number
    int die2 = rand() % 6 + 1;
    int sum = die1 + die2;

    cout << "You rolled " << die1 << " + " << die2 << " = " << sum << endl;
    return sum;
}

void playCraps() {
    int point;
    int sum = rollDice();

    // First roll rules
    if (sum == 7 || sum == 11) {
        cout << "You win!" << endl;
        return;
    } else if (sum == 2 || sum == 3 || sum == 12) {
        cout << "Craps! You lose." << endl;
        return;
    } else {
        point = sum;
        cout << "Your point is " << point << endl;
    }

    // Keep rolling until win or lose
    while (true) {
        sum = rollDice();
        if (sum == point) {
            cout << "You rolled your point again! You win!" << endl;
            break;
        } else if (sum == 7) {
            cout << "You rolled a 7 before your point. You lose." << endl;
            break;
        }
    }
}

int main() {
    srand(time(0));  // seed random number generator

    char playAgain = 'y';
    cout << "Welcome to Simple Craps!" << endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        playCraps();

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        cout << endl;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
