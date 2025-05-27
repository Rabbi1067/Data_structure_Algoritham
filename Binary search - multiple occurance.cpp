#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target number: ";
    cin >> target;

    // Using STL lower_bound and upper_bound
    auto first = lower_bound(arr.begin(), arr.end(), target);
    auto last = upper_bound(arr.begin(), arr.end(), target);

    if (first == arr.end() || *first != target) {
        cout << target << " not found in the array.\n";
    } else {
        int firstIndex = first - arr.begin();
        int lastIndex = last - arr.begin() - 1;
        int count = last - first;

        cout << "First occurrence of " << target << ": " << firstIndex << endl;
        cout << "Last occurrence of " << target << ": " << lastIndex << endl;
        cout << "Total occurrences: " << count << endl;
    }

    return 0;
}
/*
Enter size of array: 7
Enter 7 sorted elements:
1 2 4 4 4 5 6
Enter target number: 4
*/
