#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<vector<int>>&matrix,int target)
{
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = m * n - 1;
    while(low<=high)
    {
         int mid = (low + high) / 2;
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int m,n;
    cout << "Enter rows and columns: ";
    cin >>m>> n;

    vector<vector<int>>matrix(m,vector<int>(n));
    cout << "Enter matrix elements (sorted row-wise and column-wise):\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    int index = binarySearch(matrix, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
/*
Enter rows and columns: 3 3
Enter matrix:
1 2 3
4 5 6
7 8 9
Enter target: 6
*/
