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

    cout << "Enter name to search: ";
    cin >> searchName;

    ifstream file("student.dat", ios::binary);
    bool found = false;

    while (file.read((char*)&s, sizeof(s))) {
        if (strcmp(s.name, searchName) == 0) {
            cout << "Record Found!\n";
            cout << "Name: " << s.name << "\nAge: " << s.age << "\nMarks: " << s.marks << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Record not found!" << endl;
    file.close();
    return 0;
}
