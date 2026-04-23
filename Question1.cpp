#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char name[50];
    int studentID;
    int age;

public:
    void init(const char* n, int id, int a) {
        strcpy(name, n);
        studentID = id;
        age = a;
    }

    void printStudentInfo() {
        cout << "Name: " << name << ", ID: " << studentID << ", Age: " << age;
    }

    int getID() { return studentID; }
    int getAge() { return age; }
    const char* getName() { return name; }

    // Setters for swap
    void setName(const char* n) { strcpy(name, n); }
    void setID(int id) { studentID = id; }
    void setAge(int a) { age = a; }
};

void personSwap(Person &a, Person &b) {
    // Swap names
    char tempName[50];
    strcpy(tempName, a.getName());
    a.setName(b.getName());
    b.setName(tempName);

    // Swap IDs
    int tempID = a.getID();
    a.setID(b.getID());
    b.setID(tempID);

    // Swap ages
    int tempAge = a.getAge();
    a.setAge(b.getAge());
    b.setAge(tempAge);
}

int main() {
    Person p1, p2;

    p1.init("TAKONDWA", 22420033, 20);
    p2.init("CHILINDA", 22420034, 25);

    // BEFORE SWAP - each on new line
    cout << "Before Swap:" << endl;
    p1.printStudentInfo();
    cout << endl;      // Endline after first student
    p2.printStudentInfo();
    cout << endl;      // Endline after second student
    cout << endl;      // Extra blank line for clarity

    personSwap(p1, p2);

    // AFTER SWAP - each on new line
    cout << "After Swap:" << endl;
    p1.printStudentInfo();
    cout << endl;      // Endline after first student
    p2.printStudentInfo();
    cout << endl;      // Endline after second student

    return 0;
}