#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

void primMST(int n, vector<vector<pii>>& adj) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap
    key[0] = 0;
    pq.push({0, 0}); // {key, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto [weight, v] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int total_weight = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        total_weight += key[i];
    }
    cout << "Total Weight of MST: " << total_weight << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    primMST(n, adj);
    return 0;
}

/*
5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
*/
