#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    bool operator<(const Item& other) const {
        double r1 = (double)value / weight;
        double r2 = (double)other.value / other.weight;
        return r1 > r2;
    }
};

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end());
    double totalValue = 0.0;

    for (auto& item : items) {
        if (W == 0) break;
        if (item.weight <= W) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) cin >> items[i].value >> items[i].weight;
    cout << "Maximum value: " << fractionalKnapsack(W, items) << endl;
    return 0;
}
/*
3 50
60 10
100 20
120 30
*/
