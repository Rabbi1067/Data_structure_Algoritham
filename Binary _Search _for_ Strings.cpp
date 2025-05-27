/*
✅ Conditions for Binary Search on Strings
The array (or vector) of strings must be sorted lexicographically.

The search target must also be a string.

You can use the same binary search logic as with numbers—just compare strings using <, ==, >.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary Search for Strings
int binarySearch(const vector<string>& arr, const string& target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter " << n << " strings (sorted): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Optional: sort the array (only if not already sorted)
    // sort(arr.begin(), arr.end());

    string target;
    cout << "Enter string to search: ";
    cin >> target;

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "String found at index " << index << endl;
    else
        cout << "String not found in the array." << endl;

    return 0;
}
/*
Enter number of strings: 4
Enter 4 strings (sorted): apple banana mango orange
Enter string to search: mango
*/
