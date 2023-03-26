#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool checkSignature(ifstream& file) {
    const int signatureSize = 8;
    char signature[signatureSize];
    file.read(signature, signatureSize);
    return !memcmp(signature, "\x89PNG\r\n\x1a\n", signatureSize);
}

struct IHDRChunk {
    int width;
    int height;
    int bitDepth;
    int colorType;
    int compressionMethod;
    int filterMethod;
    int interlaceMethod;
};


IHDRChunk readIHDR(ifstream& file) {
    IHDRChunk ihdr;
    char buffer[4];


    file.read(buffer, 4);


    file.read(buffer, 4);
    if (memcmp(buffer, "IHDR", 4)) {
        cerr << "Ошибка: неверный тип блока IHDR" << endl;
        exit(1);
    }

    file.read(buffer, 4);
    ihdr.width = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    file.read(buffer, 4);
    ihdr.height = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    file.read(buffer, 1);
    ihdr.bitDepth = buffer[0];
    file.read(buffer, 1);
    ihdr.colorType = buffer[0];


    file.read(buffer, 4);

    return ihdr;
}

int main() {
    ifstream file("sevgu1.png", ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл" << endl;
        exit(1);
    }

    if (!checkSignature(file)) {
        cerr << "Ошибка: неверная сигнатура файла PNG" << endl;
        exit(1);
    }

    IHDRChunk ihdr = readIHDR(file);

    cout << "width: " << ihdr.width << endl;
    cout << "height: " << ihdr.height << endl;
    cout << "Glubina tsveta: " << ihdr.bitDepth << endl;
    cout << "Color tipe: " << ihdr.colorType << endl;

    file.close();

    return 0;
}
