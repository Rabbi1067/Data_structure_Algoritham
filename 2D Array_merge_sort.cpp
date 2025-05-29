#include <bits/stdc++.h>
using namespace std;

// Merge function for mergesort
void merge(vector<int>& a, int start, int mid, int end) {
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i++]);
        } else {
            temp.push_back(a[j++]);
        }
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= end) temp.push_back(a[j++]);

    for (int idx = 0; idx < temp.size(); ++idx)
        a[start + idx] = temp[idx];
}

// Recursive mergesort function
void mergesort(vector<int>& a, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergesort(a, start, mid);
        mergesort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // Input and flatten in one step
    vector<int> flat(rows * cols);
    cout << "Enter the 2D array elements:\n";
    for (int i = 0; i < rows * cols; ++i) {
        cin >> flat[i];
    }

    // Sort the 1D flattened array
    mergesort(flat, 0, flat.size() - 1);

    // Output sorted matrix
    cout << "\nSorted 2D Array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << flat[i * cols + j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
/*
2 3
5 2 9
1 3 6
*/
