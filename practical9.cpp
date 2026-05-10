// Practical 9: Inheritance — Person → Student / Employee
// Demonstrates runtime polymorphism via virtual display() and base class pointer

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {}

    virtual void display() const {
        cout << "Name       : " << name << "\n";
    }

    virtual ~Person() {}  // Virtual destructor for proper cleanup
};

// Derived class 1
class Student : public Person {
    string course;
    float  marks;
    int    year;

public:
    Student(const string& n, const string& c, float m, int y)
        : Person(n), course(c), marks(m), year(y) {}

    void display() const override {
        cout << "[ Student Record ]\n";
        Person::display();
        cout << "Course     : " << course << "\n";
        cout << "Marks      : " << marks  << "\n";
        cout << "Year       : " << year   << "\n";
    }
};

// Derived class 2
class Employee : public Person {
    string department;
    float  salary;

public:
    Employee(const string& n, const string& dept, float sal)
        : Person(n), department(dept), salary(sal) {}

    void display() const override {
        cout << "[ Employee Record ]\n";
        Person::display();
        cout << "Department : " << department << "\n";
        cout << "Salary     : Rs. " << salary  << "\n";
    }
};

int main() {
    // Array of base class pointers — runtime polymorphism in action
    Person* records[] = {
        new Student ("Alice",   "BSc (Hons) CS",  91.5f, 1),
        new Employee("Bob",     "IT Department",  72000.0f),
        new Student ("Charlie", "BSc (Hons) Math", 78.0f, 2),
        new Employee("Diana",   "Finance",         85000.0f)
    };

    int total = sizeof(records) / sizeof(records[0]);

    cout << "========= All Records =========\n";
    for (int i = 0; i < total; i++) {
        cout << "\n--- Record " << (i + 1) << " ---\n";
        records[i]->display();   // Resolved at RUNTIME (vtable dispatch)
    }

    // Clean up heap memory
    for (int i = 0; i < total; i++)
        delete records[i];

    return 0;
}
