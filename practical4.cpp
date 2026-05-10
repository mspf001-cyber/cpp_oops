// Practical 4: Menu-driven string manipulation WITHOUT using built-in string functions
// Operations: address display, concatenation, compare, length (pointer), uppercase, reverse, insert

#include <iostream>
using namespace std;

// Helper: string length using pointer arithmetic
int strLen(const char* str) {
    const char* p = str;
    while (*p) p++;
    return (int)(p - str);
}

// a. Show address of each character in string
void showAddresses(const char* str) {
    cout << "\nCharacter addresses:\n";
    cout << "Index\tChar\tAddress\n";
    cout << "-----\t----\t-------\n";
    for (int i = 0; str[i] != '\0'; i++) {
        cout << i << "\t'" << str[i] << "'\t" << (void*)&str[i] << "\n";
    }
}

// b. Concatenate src to end of dest (dest must have enough space)
void strConcat(char* dest, const char* src) {
    int i = strLen(dest);
    int j = 0;
    while (src[j] != '\0')
        dest[i++] = src[j++];
    dest[i] = '\0';
}

// c. Compare two strings: returns 0 if equal, <0 if s1<s2, >0 if s1>s2
int strCompare(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// d. Calculate length using pointers (uses strLen above)

// e. Convert all lowercase to uppercase
void toUpper(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

// f. Reverse the string in place
void reverseStr(char* str) {
    int len = strLen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp  = str[i];
        str[i]     = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// g. Insert src into dest at position pos (0-indexed)
void insertAt(char* dest, const char* src, int pos) {
    int dLen = strLen(dest);
    int sLen = strLen(src);

    if (pos < 0 || pos > dLen) {
        cout << "Invalid position!\n";
        return;
    }

    // Shift existing characters to the right
    for (int i = dLen; i >= pos; i--)
        dest[i + sLen] = dest[i];

    // Copy src characters into the gap
    for (int i = 0; i < sLen; i++)
        dest[pos + i] = src[i];
}

int main() {
    int choice;
    char str1[300], str2[200];

    do {
        cout << "\n========= String Manipulation Menu =========\n";
        cout << "1. Show address of each character\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of string (using pointer)\n";
        cout << "5. Convert lowercase to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert a string into another at a position\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1:
                cout << "Enter string: ";
                cin.getline(str1, 300);
                showAddresses(str1);
                break;

            case 2:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                strConcat(str1, str2);
                cout << "Concatenated result: " << str1 << "\n";
                break;

            case 3:
                cout << "Enter first string: ";
                cin.getline(str1, 300);
                cout << "Enter second string: ";
                cin.getline(str2, 200);
                {
                    int res = strCompare(str1, str2);
                    if (res == 0)      cout << "Strings are EQUAL\n";
                    else if (res < 0)  cout << "String 1 < String 2\n";
                    else               cout << "String 1 > String 2\n";
                }
                break;

            case 4:
                cout << "Enter string: ";
                cin.getline(str1, 300);
                cout << "Length = " << strLen(str1) << "\n";
                break;

            case 5:
                cout << "Enter string: ";
                cin.getline(str1, 300);
                toUpper(str1);
                cout << "Uppercase: " << str1 << "\n";
                break;

            case 6:
                cout << "Enter string: ";
                cin.getline(str1, 300);
                reverseStr(str1);
                cout << "Reversed: " << str1 << "\n";
                break;

            case 7: {
                cout << "Enter main string: ";
                cin.getline(str1, 200);
                cout << "Enter string to insert: ";
                cin.getline(str2, 100);
                int pos;
                cout << "Enter position (0-indexed): ";
                cin >> pos;
                cin.ignore();
                insertAt(str1, str2, pos);
                cout << "Result: " << str1 << "\n";
                break;
            }

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
