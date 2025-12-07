/*
CSC 134
M6Bonus2
Julie Yeoman
12/5/2025
*/


#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int width = 100;
    const int height = 100;

    ofstream outFile("ppm_generator.ppm");
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // PPM header
    outFile << "P3\n" << width << " " << height << "\n255\n";

    // Part 1: Pink-to-Red Diagonal Gradient

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = 255;                // constant red
            int g = 192;                // constant green
            int b = 203 - ((x + y) * 203 / (width + height - 2)); // decrease blue diagonally
            outFile << r << " " << g << " " << b << " ";
        }
        outFile << "\n";
    }

    // Part 2: Pink and Purple Horizontal Stripes
    /*
    const int stripeHeight = 10;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bool isPink = ((y / stripeHeight) % 2 == 0);
            int r = isPink ? 255 : 128;
            int g = isPink ? 192 : 0;
            int b = isPink ? 203 : 128;
            outFile << r << " " << g << " " << b << " ";
        }
        outFile << "\n";
    }
    */

    outFile.close();
    cout << "ppm_generator.ppm generated successfully!" << endl;
    return 0;
}
