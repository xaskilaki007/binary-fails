#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
    double x0, x1, step, c;
    ifstream inFile;
    ofstream outFile;

    // Open input file
    inFile.open("in.txt");
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    // Read input values
    inFile >> x0 >> x1 >> step >> c;
    inFile.close();

    // Open output file
    outFile.open("out.txt");

    // Evaluate function values and write to output file
    for (double x = x0; x <= x1; x += step) {
        double y = 0;
        for (int n = 1; n <= 10; n++) {
            y += (1.0/((2*n-1)*x))*(1+pow(-1,n)*c);
        }
        outFile << x << ", " << y << endl;
    }

    outFile.close();

    return 0;
}
