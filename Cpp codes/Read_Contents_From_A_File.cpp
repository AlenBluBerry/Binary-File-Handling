#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    char name[30];
    int age;
    float marks;
};

int main() {
    Student s;

    ifstream file("student.dat", ios::binary);
    file.read((char*)&s, sizeof(s));
    file.close();

    cout << "Name: " << s.name << "\nAge: " << s.age << "\nMarks: " << s.marks << endl;
    return 0;
}
