#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    char name[30];
    int age;
    float marks;
};

int main() {
    Student s = {"Alice", 21, 90.2};

    ofstream file("student.dat", ios::binary | ios::app);
    file.write((char*)&s, sizeof(s));
    file.close();

    cout << "Data appended successfully!" << endl;
    return 0;
}
