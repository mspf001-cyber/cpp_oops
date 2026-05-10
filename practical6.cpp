// Practical 6: Binary Search
// (i) With recursion  (ii) Without recursion

#include <iostream>
using namespace std;

// (i) Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;                          // Base case: not found

    int mid = low + (high - low) / 2;      // Avoids overflow

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearchRecursive(arr, low, mid - 1, target);
    else
        return binarySearchRecursive(arr, mid + 1, high, target);
}

// (ii) Non-Recursive (Iterative) Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

int main() {
    int n;
    cout << "Enter number of elements (must be sorted): ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    // Recursive
    int res1 = binarySearchRecursive(arr, 0, n - 1, target);
    if (res1 != -1)
        cout << "[Recursive]  Found at index " << res1 << "\n";
    else
        cout << "[Recursive]  Element not found\n";

    // Iterative
    int res2 = binarySearchIterative(arr, n, target);
    if (res2 != -1)
        cout << "[Iterative]  Found at index " << res2 << "\n";
    else
        cout << "[Iterative]  Element not found\n";

    return 0;
}
