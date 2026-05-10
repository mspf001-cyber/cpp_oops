// Practical 1: Compute sum of first n terms of the series
// S = 1 - 1/2 + 1/3 - 1/4 + ... (Alternating Harmonic Series)
// n is taken from command line argument; if absent, prompts the user.

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    int n;

    if (argc < 2) {
        cout << "No command line argument found.\n";
        cout << "Enter the number of terms: ";
        cin >> n;
    } else {
        n = atoi(argv[1]);
        if (n <= 0) {
            cout << "Invalid input. n must be a positive integer.\n";
            return 1;
        }
    }

    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double term = 1.0 / i;
        if (i % 2 == 0)
            sum -= term;
        else
            sum += term;
    }

    cout << "Sum of first " << n << " terms = " << sum << endl;
    return 0;
}
