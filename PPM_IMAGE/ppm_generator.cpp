/*
csc 134
PPM image
Julie Yeoman
12/5/2025
*/

#include <iostream>
#include <fstream>
#include <cmath>    // For sin(), cos()
using namespace std;

int main() {
    const int width = 400;
    const int height = 400;
    ofstream outFile("plasma.ppm");

    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // PPM header
    outFile << "P3\n" << width << " " << height << "\n255\n";

    // Generate plasma pattern with pink, purple, and blue
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double nx = double(x) / width;
            double ny = double(y) / height;

            // Map sine/cosine to pink, purple, blue
            int pink   = int((sin(10 * nx + 10 * ny) * 0.5 + 0.5) * 255);   // high red
            int purple = int((cos(10 * nx - 10 * ny) * 0.5 + 0.5) * 255);   // mix of red & blue
            int blue   = int((sin(10 * nx - 10 * ny) * 0.5 + 0.5) * 200 + 55); // bright blue, avoid 0

            // Write the pixel as R G B
            outFile << pink << " " << purple << " " << blue << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    cout << "Plasma PPM image 'plasma.ppm' created with pink, purple, and blue!" << endl;
    return 0;
}

