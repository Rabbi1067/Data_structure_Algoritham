#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int start, int mid, int end) {
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(a[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++) {
        a[start + idx] = temp[idx];
    }
}

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

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the 2D array elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    // Flatten 2D to 1D
    vector<int> flat;
    for (auto& row : matrix)
        for (int val : row)
            flat.push_back(val);

    // Sort the flattened array using your mergesort
    mergesort(flat, 0, flat.size() - 1);

    // Reshape 1D to 2D
    int idx = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = flat[idx++];

    // Output sorted matrix
    cout << "\nSorted 2D Array:\n";
    for (auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
/*
2 3
9 2 7
4 6 1
*/
