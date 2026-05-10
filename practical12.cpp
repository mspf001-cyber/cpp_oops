// Practical 12: Copy contents of one text file to another after removing all whitespace

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    string inputFile, outputFile;

    cout << "Enter source file name  : ";
    cin >> inputFile;
    cout << "Enter destination file  : ";
    cin >> outputFile;

    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cout << "Error: Cannot open source file \"" << inputFile << "\"\n";
        return 1;
    }

    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cout << "Error: Cannot create destination file \"" << outputFile << "\"\n";
        fin.close();
        return 1;
    }

    char ch;
    long charsCopied = 0, charsSkipped = 0;

    while (fin.get(ch)) {
        if (isspace((unsigned char)ch)) {
            charsSkipped++;
        } else {
            fout.put(ch);
            charsCopied++;
        }
    }

    fin.close();
    fout.close();

    cout << "\nDone! File copied to \"" << outputFile << "\"\n";
    cout << "Characters written  : " << charsCopied  << "\n";
    cout << "Whitespace removed  : " << charsSkipped << "\n";

    return 0;
}
