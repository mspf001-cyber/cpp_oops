// Practical 7: Calculate GCD of two numbers
// (i) With recursion  (ii) Without recursion

#include <iostream>
using namespace std;

// (i) Recursive GCD using Euclidean Algorithm
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

// (ii) Iterative GCD using Euclidean Algorithm
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0) {
        cout << "Please enter positive integers only.\n";
        return 1;
    }

    cout << "GCD (" << a << ", " << b << ") using Recursion : " << gcdRecursive(a, b) << "\n";
    cout << "GCD (" << a << ", " << b << ") using Iteration: " << gcdIterative(a, b) << "\n";

    return 0;
}
