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
    if (!f.is_open())
    {
        cout << "File not open! Error!!!";
        return 0;
    }
    while (!f.eof())
    {
        f >> s;
        st[n].surname = s;
        //    cout << s << endl;
        f >> st[n].point;
        f >> st[n].course;
        n++;
    }

    for (int i = 0; i < n; i++)
        cout << st[i].surname << " - " << st[i].point << " - " << st[i].course << endl;
    f.close();
}
