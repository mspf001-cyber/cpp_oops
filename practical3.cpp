// Practical 3: Count occurrences of each alphabet in text passed as command line arguments

#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <text words...>\n";
        cout << "Example: " << argv[0] << " Hello World\n";
        return 1;
    }

    int count[26] = {0};

    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            char ch = tolower((unsigned char)argv[i][j]);
            if (ch >= 'a' && ch <= 'z')
                count[ch - 'a']++;
        }
    }

    cout << "Alphabet\tOccurrences\n";
    cout << "---------\t-----------\n";
    bool anyFound = false;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            cout << (char)('a' + i) << "\t\t" << count[i] << "\n";
            anyFound = true;
        }
    }
    if (!anyFound)
        cout << "No alphabets found in input.\n";

    return 0;
}
