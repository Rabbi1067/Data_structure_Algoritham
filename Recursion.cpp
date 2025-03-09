#include <bits/stdc++.h>
using namespace std;
int recursive(int n) {
    if (n == 0 || n == 1) return 1;
    return n * recursive(n - 1);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> factresults(n);
    for (int i = 0; i < n; i++) {
        factresults[i] = recursive(a[i]);
    }


    for (int ans : factresults) {
        cout <<"Factorial: "<< ans <<endl;
    }
    return 0;
}
