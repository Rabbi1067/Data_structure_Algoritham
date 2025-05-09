#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> graph(n, vector<int>(n, INF));
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // for undirected graph
    }

    int s, d;
    cout << "Enter source node: ";
    cin >> s;
    cout << "Enter destination node: ";
    cin >> d;

    // Dijkstra's algorithm
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1); // to reconstruct path

    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == INF)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Print result
    if (dist[d] == INF) {
        cout << "No path exists from " << s << " to " << d << ".\n";
    } else {
        cout << "Shortest distance from " << s << " to " << d << " is: " << dist[d] << endl;

        // Reconstruct the path
        vector<int> path;
        for (int v = d; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
*/
/*
5 7
2 1 2
2 3 7
2 0 3
1 3 3
1 4 6
0 4 1
3 4 5
*/

