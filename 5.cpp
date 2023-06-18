//5. Пользователь вводит данные о студентах: Фамилия, Средняя оценка, 
//Курс. Организовать запись данных из массива структур в файл в следующем формате:
//1 строка Фамилия, 2 строка Средняя оценка, 3 строка Курс. Остальные строки
//повторяют тройками эти данные для других студентов. Организовать переменные
//для хранения информации.
#include <iostream>
#include <fstream>
#include <string>
#define N 5
using namespace std;
struct Student
{
    string surname;
    double point;
    int course;
};
int main() {
    fstream f;
    f.open("1.txt", fstream::in);
    Student st[100];
    int n = 0;
    string s;
    char c;
    if (!f.is_open())
    {
        cout << "File not open! Error!!!";
        return 0;
    }
   
    while (true)
    {
        cout << "Input surname" << endl;
        cin >> st[n].surname;
        cout << "Input point" << endl;
        //    cout << s << endl;
        cin >> st[n].point;
        cout << "Input course" << endl;
        cin >> st[n].course;
        n++;
        cout << "Continue?Y/N" << endl;
        cin >> c;
        if (c != 'Y') break;
    }
    f.close();
    fstream f2;
    f2.open("2.txt", fstream::out);
    for (int i = 0; i < n; i++)
    {
        f2 << st[i].surname << endl << st[i].point << endl << st[i].course << endl;
    }
    f2.close();
}
