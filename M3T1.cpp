/*
CSC 134
M3T1
Julie Yeoman
10/9/25
*/

#include <iostream>
using namespace std;

int main() {
    // declare variables
    int widthOne, lengthOne;
    int areaOne;

    // ask for user input
    cout << "Please enter the width and height of the first\n"
    cout << "rectangle, separated by a space or newline" << endl;
    cin >> widthOne >> lengthOne;

    // calculate answer
    areaOne = widthOne * lengthOne;


    // display results
    cout << "Rectangle has area of " << areaOne << endl;

}