/*
CSC 134
M4LAB1
Julie Yeoman
10/24/25
*/

#include <iostream>
using namespace std;

int main() {
    cout <<  "M4LAB\n";
    // declare variables
    int height, width;

    // start with set size
    // height = 5;
    // width = 5;
    cout << "How tall should the block be?" << endl;
    cin >> height;
    cout << "How wide should the block be?" << endl;
    cin >> width;
    // test: make a row of asterisks
    cout << "One row" << endl;
    for (int i=0; i <= width; i++) {
        cout << "*" << " ";
    }
    cout << endl; // finsih the row

    // make a column
    cout << "One column" << endl;
    for (int j=0; j < height; j++) {
            cout << "*" << endl;
    }
    cout << "The entire block" << endl;
    for (int j=0; j < height; j++) {
        // print one row
        for (int i=0; i < width; i++) {
            cout << "*" << " ";
        }
        cout << endl;
    }

}