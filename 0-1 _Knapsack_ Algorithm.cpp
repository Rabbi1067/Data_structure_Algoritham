#include <bits/stdc++.h>
using namespace std;

int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n) {
    if (n == 0 || W == 0)
        return 0;

    int pick = 0;
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1);

    int notPick = knapsackRec(W, val, wt, n - 1);

    return max(pick, notPick);
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter values/Profits of items:\n";
    for (int i = 0; i < n; ++i) cin >> val[i];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; ++i) cin >> wt[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    cout << "Maximum value in knapsack = " << knapsackRec(W, val, wt, n) << endl;
    return 0;
}
/*
int knapsackOptimized(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= wt[i]; --w) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}
*/
