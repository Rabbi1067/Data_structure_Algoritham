/*
#include <bits/stdc++.h>
using namespace std;

// Global constants and variables
const int MAX_VERTICES = 100;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

vector<int> adj[MAX_VERTICES];
int color[MAX_VERTICES];
int discovery[MAX_VERTICES];
int finish[MAX_VERTICES];
int dfs_time = 0;
int num_vertices;

void DFS_Visit(int u)
{
    color[u] = GRAY;
    dfs_time++;
    discovery[u] = dfs_time;

    for (int v : adj[u]) {
        if (color[v] == WHITE) {
            DFS_Visit(v);
        }
    }

    color[u] = BLACK;
    dfs_time++;
    finish[u] = dfs_time;
}

void DFS()
{
    for (int i = 0; i < num_vertices; i++) {
        color[i] = WHITE;
    }
    dfs_time = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (color[i] == WHITE) {
            DFS_Visit(i);
        }
    }
}

int main()
{
    int m;
    cout << "Enter number of vertices and edges: ";
    cin >> num_vertices >> m;

    cout << "Enter " << m << " edges (u v) [0-based indexing]:\n";
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u); // Uncomment if graph is undirected
    }

    DFS();

    cout << "\nDFS Results:\n";
    cout << "Vertex\tDiscovery\tFinish\n";
    for (int i = 0; i < num_vertices; ++i) {
        cout << i << "\t" << discovery[i] << "\t\t" << finish[i] << "\n";
    }

    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

// Global timer
int timer = 0;

// DFS function
void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited,
         vector<int>& discovery, vector<int>& finish) {
    visited[node] = true;
    timer++;
    discovery[node] = timer;

    for (auto [neighbor, weight] : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, discovery, finish);
        }
    }

    timer++;
    finish[node] = timer;
}

int main() {
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    vector<vector<pair<int, int>>> graph(num_vertices);
    vector<bool> visited(num_vertices, false);
    vector<int> discovery(num_vertices), finish(num_vertices);

    for (int i = 0; i < num_edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // Remove for directed graph
    }

    int start;
    cin >> start;

    dfs(start, graph, visited, discovery, finish);

    // Output in requested format
    cout << "\nDFS Results:\n";
    cout << "Vertex\tDiscovery\tFinish\n";
    for (int i = 0; i < num_vertices; ++i) {
        cout << i << "\t" << discovery[i] << "\t\t" << finish[i] << "\n";
    }

    return 0;
}
/*
5 7
0 1 10
0 2 5
1 2 2
1 3 1
2 1 3
2 3 9
2 4 2
0*/
