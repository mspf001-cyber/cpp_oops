// Practical 2: Remove duplicates from an array

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result[100], rSize = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < rSize; j++) {
            if (result[j] == arr[i]) {
                found = true;
                break;
            }
        }
        if (!found)
            result[rSize++] = arr[i];
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < rSize; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
