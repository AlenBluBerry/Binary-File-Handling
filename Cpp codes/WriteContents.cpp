#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    char name[30];
    int age;
    float marks;
};

int main() {
    Student s = {"John", 20, 85.5};

    ofstream file("student.dat", ios::binary);
    file.write((char*)&s, sizeof(s));
    file.close();

    cout << "Data saved successfully!" << endl;
    return 0;
}
