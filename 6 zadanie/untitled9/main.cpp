#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile) {
        cout << "File opening error";
        return 1;
    }
    int x, y, command;
    while (inFile >> x >> y >> command) {
        switch (command) {
            case 10:
                cout << "Quadcopter idet na vzlet (" << x << ", " << y << ")" << endl;
                break;
            case 20:
                cout << "Quadcopter idet na posadku (" << x << ", " << y << ")" << endl;
                break;
            case 50:
                cout << "Quadcopter letit (" << x << ", " << y << ")" << endl;
                break;
            case 60:
                cout << "Quadcopter podnimaetsya vverh (" << x << ", " << y << ")" << endl;
                break;
            case 70:
                cout << "Quadcopter opuskaetsya vniz (" << x << ", " << y << ")" << endl;
                break;
            default:
                cout << "Invalid command" << endl;
        }
    }
    inFile.close();
    return 0;
}
