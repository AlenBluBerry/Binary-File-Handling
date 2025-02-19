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
    char deleteName[30];

    cout << "Enter name to delete: ";
    cin >> deleteName;

    ifstream file("student.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {
        if (strcmp(s.name, deleteName) != 0) {
            temp.write((char*)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    remove("student.dat");
    rename("temp.dat", "student.dat");

    cout << "Record deleted successfully!" << endl;
    return 0;
}
