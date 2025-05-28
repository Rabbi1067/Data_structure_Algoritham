#include <bits/stdc++.h>
using namespace std;

int main() {
    int w = 50; // Knapsack capacity

    // Each item: {weight, value}
    vector<pair<double, double>> items = {{10, 60}, {20, 100}, {30, 120}};
    int n = items.size();

    vector<pair<double, double>> profit(n);
    for (int i = 0; i < n; i++) {
        double wt = items[i].first;
        double val = items[i].second;
        double x = val / wt;
        profit[i].first = x;
        profit[i].second = wt;
    }

    int r = w;
    double totalsum = 0.0;
    for (int i = n - 1; i >= 0; i--) {
        double wt = profit[i].second;
        double ratio = profit[i].first;

        if (wt <= r) {
            totalsum += wt * ratio;
            r -= wt;
        } else {
            totalsum += r * ratio;
            break;
        }
    }

    cout << fixed << setprecision(1) << totalsum << endl;
}
/*
2 3
9 2 7
4 6 1
*/
