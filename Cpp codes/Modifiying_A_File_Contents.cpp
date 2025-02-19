#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    char name[30];
    int age;
    float marks;
};

int main() {
    Student s;
    char searchName[30];

    fstream file("student.dat", ios::binary | ios::in | ios::out);

    cout << "Enter name to modify: ";
    cin >> searchName;

    while (file.read((char*)&s, sizeof(s))) {
        if (strcmp(s.name, searchName) == 0) {
            cout << "Enter new marks: ";
            cin >> s.marks;

            file.seekp(-sizeof(s), ios::cur);
            file.write((char*)&s, sizeof(s));

            cout << "Record updated successfully!" << endl;
            break;
        }
    }

    file.close();
    return 0;
}
