//Pазработать программу для считывания данных о студентах из файла в
//следующем формате : 1 строка Фамилия, 2 строка Средняя оценка, 3
//строка Курс.Остальные строки повторяют тройками эти данные
//для других студентов.Организовать считывание данных из файла
//в массив структур.Организовать переменные для хранения информации.
#include <iostream>
#include <array>
#include <time.h>
#include <string>
#include <fstream>
#define N 5
using namespace std;
struct Student {
	string surname;
	double point;
	int course;
};
int main() {
	ifstream  f;
	f.open("1.txt", ifstream::in);
	Student st[100];
	int n=0;
	string s;
	while (!f.eof())
	{
		f >> s;
		st[n].surname = s;
		f >> st[n].point;
		f >> st[n].course;
		n++;
	}
	for (int i = 0; i < n; i++)
		cout << st[i].surname << " - " << st[i].point << " - " << st[i].course << endl;
	f.close();
}
