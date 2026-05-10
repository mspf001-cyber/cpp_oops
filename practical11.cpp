// Practical 11: Store 5 Student objects to a binary file and retrieve them
// Fields: Roll No., Name, Class, Year, Total Marks

#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int   rollNo;
    char  name[50];
    char  cls[20];
    int   year;
    float totalMarks;

    void input(int num) {
        cout << "\n--- Enter details for Student " << num << " ---\n";
        cout << "Roll No.     : "; cin >> rollNo;     cin.ignore();
        cout << "Name         : "; cin.getline(name, 50);
        cout << "Class        : "; cin.getline(cls,  20);
        cout << "Year         : "; cin >> year;
        cout << "Total Marks  : "; cin >> totalMarks; cin.ignore();
    }

    void display() const {
        cout << "Roll No.    : " << rollNo     << "\n";
        cout << "Name        : " << name       << "\n";
        cout << "Class       : " << cls        << "\n";
        cout << "Year        : " << year       << "\n";
        cout << "Total Marks : " << totalMarks << "\n";
        cout << "----------------------------\n";
    }
};

int main() {
    const char* filename = "students.dat";
    const int   COUNT    = 5;

    // ---- Write phase ----
    {
        ofstream fout(filename, ios::binary | ios::trunc);
        if (!fout) {
            cout << "Error: Could not open file for writing.\n";
            return 1;
        }

        cout << "=== Enter details for " << COUNT << " students ===\n";
        for (int i = 1; i <= COUNT; i++) {
            Student s;
            s.input(i);
            fout.write(reinterpret_cast<char*>(&s), sizeof(Student));
        }
        fout.close();
        cout << "\nAll records saved to \"" << filename << "\" successfully.\n";
    }

    // ---- Read & display phase ----
    {
        ifstream fin(filename, ios::binary);
        if (!fin) {
            cout << "Error: Could not open file for reading.\n";
            return 1;
        }

        cout << "\n=== Retrieved Records from File ===\n\n";
        Student s;
        int count = 1;
        while (fin.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            cout << "Record " << count++ << ":\n";
            s.display();
        }
        fin.close();
    }

    return 0;
}
