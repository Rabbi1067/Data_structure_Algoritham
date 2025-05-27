#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&arr,int key){
int l=0;
int h=arr.size()-1;
while(l<=h){
int m=(l+h)/2;
if(arr[m]==key) return m;
else if(arr[m]>key) h=m-1;
else l=m+1;
}
return -1;
}
int main() {
    int n;
    cout << "Enter number of elements in the sorted array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
     // Optional: sort the array (only if not already sorted)
    // sort(arr.begin(), arr.end());

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
/*
5
1 3 5 7 9
*/
