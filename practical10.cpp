// Practical 10: Triangle class
// - Exception handling: all sides > 0, sum of any two > third
// - Overloaded area():
//     area()              → Heron's formula (any triangle)
//     area(base, height)  → right-angled triangle formula

#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Triangle {
    double a, b, c;

    // Private validation — throws on invalid triangle
    void validate() const {
        if (a <= 0 || b <= 0 || c <= 0)
            throw invalid_argument("All sides must be greater than 0.");

        if ((a + b) <= c || (b + c) <= a || (a + c) <= b)
            throw invalid_argument(
                "Triangle inequality violated: sum of any two sides must be "
                "greater than the third side."
            );
    }

public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {
        validate();
    }

    // Overload 1: Area using Heron's formula (general triangle)
    double area() const {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Overload 2: Area of right-angled triangle given base and height
    double area(double base, double height) const {
        if (base <= 0 || height <= 0)
            throw invalid_argument("Base and height must be positive.");
        return 0.5 * base * height;
    }

    void displaySides() const {
        cout << "Triangle sides: a=" << a << ", b=" << b << ", c=" << c << "\n";
    }
};

int main() {
    try {
        double a, b, c;
        cout << "Enter three sides of the triangle: ";
        cin >> a >> b >> c;

        Triangle t(a, b, c);   // May throw here
        t.displaySides();

        cout << "Area using Heron's formula      : " << t.area() << "\n";

        double base, height;
        cout << "Enter base and height for right-angle area calculation: ";
        cin >> base >> height;

        cout << "Area using (0.5 * base * height): " << t.area(base, height) << "\n";

    } catch (const invalid_argument& e) {
        cout << "[Exception] " << e.what() << "\n";
    } catch (const exception& e) {
        cout << "[Unexpected error] " << e.what() << "\n";
    }

    return 0;
}
