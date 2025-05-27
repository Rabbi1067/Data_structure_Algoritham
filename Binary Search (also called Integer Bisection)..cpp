#include <iostream>
using namespace std;

// Function to find the integer square root of x
int integerSquareRoot(int x) {
    int low = 0, high = x, ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Avoid overflow by using 1LL * mid * mid
        if (1LL * mid * mid <= x) {
            ans = mid;         // mid might be the answer
            low = mid + 1;     // try a bigger number
        } else {
            high = mid - 1;    // try a smaller number
        }
    }

    return ans;
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    int result = integerSquareRoot(x);

    cout << "The integer square root of " << x << " is: " << result << endl;

    return 0;
}
