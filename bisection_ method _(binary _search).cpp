#include <iostream>
#include <iomanip>
using namespace std;

double squareRoot(double x) {
    double low = 0, high = x;
    if (x < 1) high = 1;  // for numbers between 0 and 1

    double mid;
    while (high - low > 1e-6) {
        mid = (low + high) / 2.0;

        if (mid * mid <= x)
            low = mid;
        else
            high = mid;
    }

    return (low + high) / 2.0;
}

int main() {
    double x;
    cout << "Enter a number: ";
    cin >> x;

    if (x < 0) {
        cout << "Invalid input. Cannot compute square root of negative number." << endl;
        return 0;
    }

    cout << fixed << setprecision(6);
    cout << "Square root of " << x << " is: " << squareRoot(x) << endl;

    return 0;
}
