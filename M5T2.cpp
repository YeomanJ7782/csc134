/*
CSC 134
M5T2
Julie Yeoman
11/8/2025
*/

#include <iostream>
using namespace std;

// given 2 numbers, print out nicely on a line.
void printResult(int number, int result) {
    cout << number << " squared = " << result << endl;
}

// given a number return the square of it
int square(int number) {
    int result;
    result = number * number; // squared
    return result;
}

int main() {
    // count some numbers
    // and find a result for each
    int count = 1;
    int result;

    // this version will be squares

    while (count <= 10) {
        result = square(count); // squared
        printResult(count, result);
        count++;

    }


}